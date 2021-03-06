#include "FrameBufferController.h"

bool FrameBufferController::load(FrameBuffer* frameBuffer) {
    GLuint id = 0;
    GLuint depthBufferId = 0;

    if(glIsFramebuffer(frameBuffer->getId()) == GL_TRUE) {
        glDeleteFramebuffers(1, &frameBuffer->id());
        frameBuffer->getColorBuffers().clear();
    }
    
    glGenFramebuffers(1, &id);

    glBindFramebuffer(GL_FRAMEBUFFER, id);
        Texture colorBuffer = Texture(
            frameBuffer->getHeight(),
            frameBuffer->getWidth(),
            GL_RGBA,
            GL_RGBA,
            true
        );

        TextureController::loadEmpty(&colorBuffer);
        frameBuffer->addColorBuffer(colorBuffer);
        FrameBufferController::createBufferRender(depthBufferId, frameBuffer->getWidth(), frameBuffer->getHeight(), GL_DEPTH24_STENCIL8);
        frameBuffer->setDepthBufferId(depthBufferId);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, frameBuffer->getColorBuffers()[0].getId(), 0);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, frameBuffer->getDepthBufferId());
        
        if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            glDeleteFramebuffers(1, &id);
            glDeleteRenderbuffers(1, &depthBufferId);
            frameBuffer->getColorBuffers().clear();
            std::cout << "Error : FBO cannot be constructed" << std::endl;
            return false;
        }


    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return true;
}

/**
 * @return id buffer (Render or Stencil)
 */
GLuint FrameBufferController::createBufferRender(GLuint &id, float width, float height, GLenum internalFormat) {
    
    if(glIsRenderbuffer(id) == GL_TRUE)
        glDeleteRenderbuffers(1, &id);

    glGenRenderbuffers(1, &id);
    
    glBindRenderbuffer(GL_RENDERBUFFER, id);
        glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    return id;
}

void FrameBufferController::render(FrameBuffer* frameBuffer, Model* model, glm::mat4 &projection, glm::mat4 &modelview) {
    
    glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer->getId());
        glm::mat4 modelviewSave = modelview;

        Shader* shader = model->getShader();

        modelview = glm::translate(modelview, model->getPosition());
	    modelview = glm::rotate(modelview, model->getRotation()->getAngle(), model->getRotation()->getAxis());

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glViewport(0, 0, frameBuffer->getWidth(), frameBuffer->getHeight());

        glUseProgram(shader->getProgramId());

        glBindVertexArray(model->getVaoId());

            mat4 modelviewProjection = projection * modelview;

            ShaderController::loadMatrix4f(shader, "modelviewProjection", modelviewProjection);
            //glUniformMatrix4fv(glGetUniformLocation(shader->getProgramId(), "modelviewProjection"), 1, GL_FALSE, value_ptr(modelviewProjection));
            //glUniformMatrix4fv(glGetUniformLocation(model->getShader()->getProgramId(), "projection"), 1, GL_FALSE, value_ptr(projection));
            //glUniformMatrix4fv(glGetUniformLocation(model->getShader()->getProgramId(), "modelview"), 1, GL_FALSE, value_ptr(modelview));

            glBindTexture(GL_TEXTURE_2D, model->getTexture()->getId());
            glDrawArrays(GL_TRIANGLES, 0, model->getMesh()->getVertices().size());
            glBindTexture(GL_TEXTURE_2D, 0);

        glBindVertexArray(0);
        
        glUseProgram(0);

    modelview = modelviewSave;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
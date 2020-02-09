#include "ShaderController.h"

bool ShaderController::compile(GLuint &id, GLenum type, std::string const &file) {
    std::cout << "Shader compilation... ";
    if((id = glCreateShader(type)) != 0) {

        std::ifstream stream;
        if((stream = std::ifstream(file.c_str()))) {

            std::string src;
            std::string line;

            while(getline(stream, line)) {
                src += line + "\n";
            }
            stream.close();

            const GLchar* chars = src.c_str();

            glShaderSource(id, 1, &chars, 0);
            glCompileShader(id);

            GLint compileError = 0;

            glGetShaderiv(id, GL_COMPILE_STATUS, &compileError);

            if(compileError == GL_TRUE) {
                std::cout << "done !" << std::endl;
                return true;
            }
            else {
                GLint lenghtCompileError = 0;
                glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenghtCompileError);

                char *error = new char[lenghtCompileError + 1];

                glGetShaderInfoLog(id, lenghtCompileError, &lenghtCompileError, error);
                error[lenghtCompileError] = '\0';

                std::cout << "\nError: " << error << std::endl;

                delete[] error;
                error = NULL;
                glDeleteShader(id);
                return false;
            }
        }
        else {
            std::cout << "\nError: file don't exist or is unreadable" << std::endl;
            
            return false;
        }
    }
    else {
        std::cout << "\nError: type " << type << " don't exist" << std::endl;
        return false;
    }
}

bool ShaderController::load(Shader* shader) {
    GLuint programId, vertexId, fragmentId;

    if(!ShaderController::compile(vertexId, GL_VERTEX_SHADER, shader->getVertexFile()))
        return false;
    if(!ShaderController::compile(fragmentId, GL_FRAGMENT_SHADER, shader->getFragmentFile()))
        return false;

    programId = glCreateProgram();

    glAttachShader(programId, vertexId);
    glAttachShader(programId, fragmentId);

    glBindAttribLocation(programId, 0, "in_Vertex");
    glBindAttribLocation(programId, 1, "in_Color");
    glBindAttribLocation(programId, 2, "in_TexCoord0");

    
    glLinkProgram(programId);

    glLinkProgram(programId);

    GLint linkShaderError = 0;
    glGetProgramiv(programId, GL_LINK_STATUS, &linkShaderError);

    if(linkShaderError == GL_TRUE) {
        shader->setProgramId(programId);
        shader->setVertexId(vertexId);
        shader->setFragmentId(fragmentId);
        return true;
    }
    else {
        GLint lenghtLinkShaderError = 0;
        glGetShaderiv(programId, GL_INFO_LOG_LENGTH, &lenghtLinkShaderError);

        char* error = new char[lenghtLinkShaderError + 1];
        glGetShaderInfoLog(programId, lenghtLinkShaderError, &lenghtLinkShaderError, error);

        error[lenghtLinkShaderError] = '\0';

        std::cout << "Erreur: " << error << std::endl;

        delete[] error;
        error = NULL;
        glDeleteShader(programId);
        return false;
    }

}
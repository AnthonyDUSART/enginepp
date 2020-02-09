#pragma once

#include <GL/glew.h>
#include <string>
#include <map>

class Shader
{
protected:
    std::string m_vertexFile;
    std::string m_fragmentFile;
    GLuint m_programId;
    GLuint m_vertexId;
    GLuint m_fragmentId;
    std::map<int, std::string> m_attributes;

public:
    Shader(std::string vertexFile = "", std::string fragmentFile = "", GLuint programId = 0, GLuint vertexId = 0, GLuint fragmentId = 0, std::map<int, std::string> attributes = std::map<int, std::string>());
    ~Shader();
    std::string getVertexFile() const;
    void setVertexFile(std::string vertexFile);
    std::string getFragmentFile() const;
    void setFragmentFile(std::string fragmentFile);
    GLuint getProgramId() const;
    void setProgramId(GLuint programId);
    GLuint getVertexId() const;
    void setVertexId(GLuint vertexId);
    GLuint getFragmentId() const;
    void setFragmentId(GLuint fragmentId);
    std::map<int, std::string> getAttributes() const;
    void setAttributes(std::map<int, std::string> attributes);
    void addAttribute(int id, std::string name);
};

    #include "Shader.h"
    
    Shader::Shader(Shader const& shader) {
        *this = shader;
    }

    Shader::Shader(std::string vertexFile, std::string fragmentFile, GLuint programId, GLuint vertexId, GLuint fragmentId, std::map<int, std::string> attributes) {
        m_vertexFile = vertexFile;
        m_fragmentFile = fragmentFile;
        m_programId = programId;
        m_vertexId = vertexId;
        m_fragmentId = fragmentId;
        m_attributes = attributes;
    }

    Shader::~Shader() {
        glDeleteShader(m_vertexId);
        glDeleteShader(m_fragmentId);
        glDeleteProgram(m_programId);
    }

    Shader& Shader::operator=(Shader const &shader) {
        m_vertexFile = shader.getVertexFile();
        m_fragmentFile = shader.getFragmentFile();
        return *this;
    }

    std::string Shader::getVertexFile() const {
        return m_vertexFile;
    }

    void Shader::setVertexFile(std::string vertexFile) {
        m_vertexFile = vertexFile;
    }

    std::string Shader::getFragmentFile() const {
        return m_fragmentFile;
    }

    void Shader::setFragmentFile(std::string fragmentFile) {
        m_fragmentFile = fragmentFile;
    }

    GLuint Shader::getProgramId() const {
        return m_programId;
    }

    void Shader::setProgramId(GLuint programId) {
        m_programId = programId;
    }

    GLuint Shader::getVertexId() const {
        return m_vertexId;
    }

    void Shader::setVertexId(GLuint vertexId) {
        m_vertexId = vertexId;
    }

    GLuint Shader::getFragmentId() const {
        return m_fragmentId;
    }

    void Shader::setFragmentId(GLuint fragmentId) {
        m_fragmentId = fragmentId;
    }

    std::map<int, std::string> Shader::getAttributes() const {
        return m_attributes;
    }

    void Shader::setAttributes(std::map<int, std::string> attributes) {
        m_attributes = attributes;
    }

    void Shader::addAttribute(int id, std::string name) {
        m_attributes.insert({id, name});
    }
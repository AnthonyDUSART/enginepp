#include "MeshController.h"

void MeshController::loadObj(Mesh* mesh, std::string file) {
	std::ifstream stream = std::ifstream(file);

	if (stream) {
		std::string line;

		std::vector<glm::vec3> vertices = std::vector<glm::vec3>();
		std::vector<glm::vec2> textureCoords = std::vector<glm::vec2>();
		std::vector<glm::vec3> normals = std::vector<glm::vec3>();
		std::vector<int> faces = std::vector<int>();

		std::cout << "Lecture du fichier \"" << file << "\" en cours..." << std::endl;
		while (getline(stream, line)) {
			if (line.substr(0, 2) == "v ") {
				std::istringstream s(line.substr(2));
				glm::vec3 v;
				s >> v.x;
				s >> v.y;
				s >> v.z;
				vertices.push_back(v);
			}
			else if (line.substr(0, 3) == "vt ") {
				std::istringstream s(line.substr(3));
				glm::vec2 vt;
				s >> vt.x;
				s >> vt.y;
				textureCoords.push_back(vt);
			}
			else if (line.substr(0, 3) == "vn ") {
				std::istringstream s(line.substr(3));
				glm::vec3 vn;
				s >> vn.x;
				s >> vn.y;
				s >> vn.z;
				normals.push_back(vn);
			}
			else if (line.substr(0, 2) == "f ") {
				std::string a, b, c;
				std::string segment;

				std::istringstream s = std::istringstream(line.substr(2));
				s >> a; s >> b; s >> c;

				s = std::istringstream(a);

				while (getline(s, segment, '/')) {
					faces.push_back(stoi(segment) - 1);
				}
				s = std::istringstream(b);

				while (getline(s, segment, '/')) {
					faces.push_back(stoi(segment) - 1);
				}

				s = std::istringstream(c);

				while (getline(s, segment, '/')) {
					faces.push_back(stoi(segment) - 1);
				}
			}
		}

		std::cout << "Lecture du fichier terminee avec succes !" << std::endl;


		for (int i(0); i < faces.size(); i+=3) {
			int iv, it, in;

			iv = faces.at(i);
			it = faces.at(i+1);
			in = faces.at(i+2);
			mesh->addVertex(
				vertices.at(iv)
			);
			mesh->addTextureCoord(
				textureCoords.at(it)
			);
			mesh->addNormal(
				normals.at(in)
			);
		}

	}
	else
		std::cout << "Erreur, impossible d'ouvrir la lecture sur le fichier \"" << file << "\"" << std::endl;
}

void MeshController::load(Mesh* mesh) {
	if (glIsBuffer(mesh->vboId()) == GL_TRUE)
		glDeleteBuffers(1, &mesh->vboId());

	mesh->setVerticesBytes(mesh->getVertices().size() * sizeof(glm::vec3));
	mesh->setTextureCoordsBytes(mesh->getTextureCoords().size() * sizeof(glm::vec2));
	mesh->setNormalsBytes(mesh->getNormals().size() * sizeof(glm::vec3));

	glGenBuffers(1, &mesh->vboId());
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vboId());

	glBufferData(GL_ARRAY_BUFFER, mesh->getVerticesBytes() + mesh->getTextureCoordsBytes(), 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, mesh->getVerticesBytes(), mesh->getVertices().data());
	glBufferSubData(GL_ARRAY_BUFFER, mesh->getVerticesBytes(), mesh->getTextureCoordsBytes(), mesh->getTextureCoords().data());

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
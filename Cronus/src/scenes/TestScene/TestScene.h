#pragma once

#include <core/Scene.h>
#include <core/GameObject.h>
#include <rendering/Mesh.h>
#include <rendering/Renderer.h>
#include <components/MeshRenderer.h>
#include <components/Camera.h>

#include <vector>

#include "Rotator.h"
#include "Translator.h"

class TestScene: public Scene {
	void Start() override {
		std::vector<float> vertices = {
			//Farther
			 0.5f,  0.5f, -0.5f,   0.0f, 0.0f, // top right
			 0.5f, -0.5f, -0.5f,   0.0f, 1.0f, // bottom right
			-0.5f, -0.5f, -0.5f,   1.0f, 1.0f, // bottom left
			-0.5f,  0.5f, -0.5f,   1.0f, 0.0f,  // top left 
			//Closer
			 0.5f,  0.5f,  0.5f,   1.0f, 1.0f, // top right
			 0.5f, -0.5f,  0.5f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f,  0.5f,   0.0f, 0.0f, // bottom left
			-0.5f,  0.5f,  0.5f,   0.0f, 1.0f,  // top left 

			 0.5f,  0.5f, -0.5f,   1.0f, 1.0f, // top right
			 0.5f,  0.5f,  0.5f,   1.0f, 0.0f, // bottom right
			-0.5f,  0.5f,  0.5f,   0.0f, 0.0f, // bottom left
			-0.5f,  0.5f, -0.5f,   0.0f, 1.0f,  // top left 

			 0.5f, -0.5f, -0.5f,   1.0f, 1.0f, // top right
			 0.5f, -0.5f,  0.5f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f,  0.5f,   0.0f, 0.0f, // bottom left
			-0.5f, -0.5f, -0.5f,   0.0f, 1.0f,  // top left 

			 0.5f,  0.5f, -0.5f,   1.0f, 1.0f, // top right
			 0.5f, -0.5f, -0.5f,   1.0f, 0.0f, // bottom right
			 0.5f, -0.5f,  0.5f,   0.0f, 0.0f, // bottom left
			 0.5f,  0.5f,  0.5f,   0.0f, 1.0f,  // top left 

			-0.5f,  0.5f, -0.5f,   1.0f, 1.0f, // top right
			-0.5f, -0.5f, -0.5f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f,  0.5f,   0.0f, 0.0f, // bottom left
			-0.5f,  0.5f,  0.5f,   0.0f, 1.0f,  // top left 
		};

		std::vector<unsigned int> indices = {
			0, 1, 3,
			1, 2, 3,

			4, 5, 7,
			5, 6, 7,

			8, 9, 11,
			9, 10, 11,

			12, 13, 15,
			13, 14, 15,

			16, 17, 19,
			17, 18, 19,

			20, 21, 23,
			21, 22, 23,
		};

		Mesh* mesh = new Mesh(vertices, indices);
		Component* meshRenderer = new MeshRenderer(mesh);
		GameObject *box = new GameObject();
		box->AddComponent(meshRenderer);
		box->AddComponent(new Rotator(glm::vec3(1.0f, 0.0f, 0.0f)));


		Mesh* cloneMesh = new Mesh(vertices, indices);
		Component* cloneMeshRenderer = new MeshRenderer(cloneMesh);
		GameObject* cloneBox = new GameObject();
		cloneBox->GetTransform()->Translate(glm::vec3(1.0f, 0.0f, 0.0f));
		cloneBox->AddComponent(meshRenderer);
		cloneBox->AddComponent(new Translator());
		cloneBox->AddComponent(new Rotator(glm::vec3(1.0f, 1.0f, 0.0f)));
		
		AddObject(box);
		AddObject(cloneBox);

		GetRootObject()->Start();
	}
};
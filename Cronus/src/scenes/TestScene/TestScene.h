#pragma once

#include <core/Scene.h>
#include <core/GameObject.h>
#include <rendering/Mesh.h>
#include <rendering/Renderer.h>
#include <components/MeshRenderer.h>
#include <components/Camera.h>

#include <vector>

#include "Rotator.h"

class TestScene: public Scene {
	void Start() override {
		std::vector<float> vertices = {
			-0.5f,  0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f
		};

		std::vector<unsigned int> indices = {
			0, 2, 3,
			0, 3, 1
		};

		Mesh* mesh = new Mesh(vertices, indices);
		Component* meshRenderer = new MeshRenderer(mesh);
		GameObject *triangle = new GameObject();
		triangle->AddComponent(meshRenderer);
		triangle->AddComponent(new Rotator());

		
		AddObject(triangle);

		GetRootObject()->Start();
	}
};
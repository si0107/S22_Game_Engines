#include "pchPigu.h"

#include "PiguApp.h"
#include "GWindow.h"
#include "glad/glad.h"
//#include "Pigustbi/pigu_stb_image.h"

//Implement Run method

namespace Pigu
{
	void PiguApp::Run()
	{
		PIGU_LOG("Pigu running...\n");

		Pigu::GWindow::Init();
		

		Pigu::GWindow::GetWindow()->CreateWindow(800, 600, "game window");

		//define vertices
		float vertices[] = {
			-0.5f, -0.5f,	//bottom - left
			-0.5f, 0.5f,	//top - left
			0.5f, 0.5f,		//top - right
			0.5f, -0.5f		//bottom - right
		};

		//define edges between vertices
		unsigned int indices[] = {
			0, 1, 2,	//upper - left triangle
			0, 2, 3		//bottom - right triangle
		};

		//VBO - vertex buffer object
		//VAO - vertex array object
		//EBO - edges buffer object (indices)
		unsigned int VBO, VAO, EBO;

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		//copy data into VBO
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		//copy data into EBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (void*)0);
		glEnableVertexAttribArray(0);

		// SHADER CODE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		std::string vertex_code{ R"()" };


		//NEW CODEEEEE
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_set_flip_vertically_on_load(true);//new

		int width, height, numChannels; //new
		unsigned char* data = stbi_load("../Air/Assets/Star.png", &width, &height, &numChannels, 0) //new


		//Almost infinite loop to make sure game is rendering 
		while (true) 
		{
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //NEW 
			glClear(GL_COLOR_BUFFER_BIT); //NEW 

			glUseProgram(shaderProgram); //NEW 
			glBindVertexArray(VAO); //NEW 


			Pigu::GWindow::GetWindow()->SwapBuffers();
			Pigu::GWindow::GetWindow()->CollectEvents();
		}
	}

	//Whatever happens on each function of the Run loop, update here
	void PiguApp::OnUpdate()
	{
		//Currently it will do nothing
	}

}
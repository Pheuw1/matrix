
    /**************************************************************************
     *                                                                        *
     *   Author: Ivo Filot <ivo@ivofilot.nl>                                  *
     *                                                                        *
     *   This file is distributed under the Academic Free License 3.0         *
     *   in the hope that it will be useful, but WITHOUT ANY WARRANTY;        *
     *   without even the implied warranty of MERCHANTABILITY or FITNESS      *
     *   FOR A PARTICULAR PURPOSE.                                            *
     *                                                                        *
     **************************************************************************/

    #ifdef WIN32
        #pragma comment (lib, "glew32s.lib")
        #define GLEW_STATIC
    #endif

    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <iostream>
    #define GLM_FORCE_RADIANS
    #include <glm/glm.hpp>
    #include <glm/gtx/transform.hpp>
    #include <string>
    #include "ft_mat.hpp"
    #include "ft_vec.hpp"

    using namespace ft;
    /*
    * execute this function is an error is encountered
    */
    static void error_callback(int error, const char* description) {
        std::cerr << "Error: "<< description << std::endl;
    }

    /*
    * execute this function every time a key is pressed
    */
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }
    /*
    * define cube object
    */
    static const float vertices[72] =
    {
        -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, // bottom
        -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f,     // front
        0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f,     // right
        0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, // back
        -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, // left
        -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f      // top
    };
    static const float colors[72] = {
        1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f
    };
    static const unsigned int indices[36] = {
        0,1,2,2,3,0,        // bottom
        4,5,6,6,7,4,        // front
        8,9,10,10,11,8,     // right
        12,13,14,14,15,12,  // back
        16,17,18,18,19,16,  // left
        20,21,22,22,23,20   // top
    };
    /*
    * Vertex shader program
    */
    static const char* vertex_shader_text =
    "#version 330 core\n"
    "uniform mat4 mvp;\n"
    "in vec3 pos;\n"
    "in vec3 col;\n"
    "out vec3 color;\n"

    "void main()\n"
    "{\n"
    "    gl_Position = mvp * vec4(pos, 1.0);\n"
    "    color = col;\n"
    "}\n";

    /*
    * fragment shader program
    */
    static const char* fragment_shader_text =
    "#version 330 core\n"
    "in vec3 color;\n"
    "out vec4 outcol;\n"
    "void main()\n"
    "{\n"
    "    outcol = vec4(color, 1.0);\n"
    "}\n";

    static void check_shader_error(GLuint shader, GLuint flag, bool is_program, const std::string& error_message) {
        GLint success = 0;
        GLchar error[1024] = { 0 };

        if(is_program) {
            glGetProgramiv(shader, flag, &success);
        } else {
            glGetShaderiv(shader, flag, &success);
        }

        if(success == GL_FALSE) {
            if(is_program) {
                glGetProgramInfoLog(shader, sizeof(error), NULL, error);
            } else {
                glGetShaderInfoLog(shader, sizeof(error), NULL, error);
            }

            std::cerr << error_message << ": '" << error << "'" << std::endl;
        }
    }


    int main() {
        std::cout << "Start program" << std::endl;

        // create pointer to new window
        GLFWwindow* window;

        // set error callback function
        glfwSetErrorCallback(error_callback);

        // try to initialize glfw
        if (!glfwInit()) {
            std::cerr << "Could not initialize glfw, exiting..." << std::endl;
            exit(EXIT_FAILURE);
        }

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        // create a new window
        window = glfwCreateWindow(640, 480, "display", NULL, NULL);

        // check if the window was succesfully created
        if (!window) {
            std::cerr << "Could not build window, exiting..." << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        // set a key callback function
        glfwSetKeyCallback(window, key_callback);

        // make the created windows the active context
        glfwMakeContextCurrent(window);

        // initialize GLEW
        // remember to initialize GLEW after you have made the current window
        // in context
        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            std::cerr << "Could not initialize GLEW" << std::endl;
        }

        // set swap interval
        glfwSwapInterval(1);

        // declare variables
        GLuint vao, vbo[3], vertex_shader, fragment_shader, program;
        GLint mvp_location;

        // load shape into buffer
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glGenBuffers(3, vbo);

        // bind vertices
        glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
        glBufferData(GL_ARRAY_BUFFER, 72 * sizeof(float), &vertices[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        // bind colors
        glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
        glBufferData(GL_ARRAY_BUFFER, 72 * sizeof(float), &colors[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        // bind indices
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
        glBindVertexArray(0);

        // load vertex shader
        vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
        glCompileShader(vertex_shader);
        check_shader_error(vertex_shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");

        // load fragment shader
        fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
        glCompileShader(fragment_shader);
        check_shader_error(fragment_shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");

        // construct program and attach shaders
        program = glCreateProgram();
        glAttachShader(program, vertex_shader);
        glAttachShader(program, fragment_shader);

        // bind attributes
        glBindAttribLocation(program, 0, "pos");
        glBindAttribLocation(program, 1, "col");

        // always link after binding attributes
        glLinkProgram(program);
        check_shader_error(program, GL_LINK_STATUS, true, "Program linking failed: ");
        glValidateProgram(program);
        check_shader_error(program, GL_VALIDATE_STATUS, true, "Program validation failed: ");

        // set uniform variables in shader after linking
        mvp_location = glGetUniformLocation(program, "mvp");

        glEnable(GL_DEPTH_TEST);
        // get width window width and height

        int width = 640;
        int height = 480;
    
        glfwGetFramebufferSize(window, &width, &height);
        float ratio = (float)width / (float) height;

        // load program and copy mvp matrix
        matrix<float> view = camera(vector<float>{0.0f, 0.0f, -5.0f}, vector<float>{0.0, 0.0, 0.0}, vector<float>{0.0, 1.0, 0.0});
        matrix<float> projection = perspective(0.25 * M_PI, 1.33, 0.1, 10.0);
        std::cout << view << std::endl;
        std::cout << projection << std::endl;
        // start loop

        while (!glfwWindowShouldClose(window)) {

            // set the viewport to match width and height
            glViewport(0, 0, width, height);

            // clear the buffer
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // black background
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            matrix<float> model = rotate((float) glfwGetTime(), vector<float>{1.0, 1.0, 1.0});
            
            auto mvp = model * view * projection;
            vector<float> buffer = vector<float>(mvp.begin(), mvp.end());

            glUseProgram(program);
            glUniformMatrix4fv(mvp_location, 1, GL_FALSE, &buffer[0]);

            glBindVertexArray(vao);
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

            // swap buffers
            glfwSwapBuffers(window);

            // poll for any events
            glfwPollEvents();
        }
        // destroy the window and clean up
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }
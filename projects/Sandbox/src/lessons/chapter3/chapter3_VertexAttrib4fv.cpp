#include "chapter3_VertexAttrib4fv.h"
#include <vmath.h>

GLuint CreateProgram();

Chapter3_VertexAttrib4fv::Chapter3_VertexAttrib4fv()
:Lesson("Chapter3_VertexAttrib4fv")
{
}

void Chapter3_VertexAttrib4fv::render(double currentTime)
{
    const GLfloat red[] = 
    {
        (float)sin(currentTime) * 0.5f + 0.5f,
        (float)cos(currentTime) * 0.5f + 0.5f,
        0.0f, 1.0f
    };

    glClearBufferfv(GL_COLOR, 0, red);

    glUseProgram(m_program);
    glBindVertexArray(m_vao);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}


void Chapter3_VertexAttrib4fv::startup()
{
    glPointSize(40.0f);
    m_program = CreateProgram();
    glGenVertexArrays(1, &m_vao);
}


void Chapter3_VertexAttrib4fv::shutdown()
{
    glDeleteProgram(m_program);
    glDeleteVertexArrays(1, &m_vao);
}


GLuint CreateProgram()
{
    static const GLchar *vertex_src[]=
    {
        "#version 430 core\n"
        "const vec4 verts[3] = vec4[3](\
            vec4(-0.5f, -0.5f, 0.5f, 1.0f),\
            vec4(0.5f, -0.5f, 0.5f, 1.0f),\
            vec4(0.0f, 0.5f, 0.5f, 1.0f));"
        "void main(void){"
        "gl_Position=verts[gl_VertexID];"
        "}"
    };


    static const GLchar *fragment_src[]=
    {
        "#version 430 core\n"
        "out vec4 m_FragColor;"
        "void main(void){"
        "m_FragColor=vec4(0.0f, 0.8f, 1.0f, 1.0f);"
        "}"
    };

    GLuint program = glCreateProgram();
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, vertex_src, NULL);
    glShaderSource(fragment, 1, fragment_src, NULL);


    glCompileShader(vertex);
    GLint shaderSuccess;
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &shaderSuccess);
    if (!shaderSuccess)
    {
        printf("Verted shader failed to compile!\n");
    }


    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &shaderSuccess);
    if (!shaderSuccess)
    {
        printf("Fragment shader failed to compile!\n");
    }


    glAttachShader(program, vertex);
    glAttachShader(program, fragment);

    glLinkProgram(program);
    
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        printf("Program Linking Failed!\n");
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    printf("Compilation Done!\n");

    return program;
}
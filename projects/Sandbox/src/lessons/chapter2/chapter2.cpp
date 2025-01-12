#include "chapter2.h"
#include <vmath.h>

static GLuint CreateProgram(RenderOptionE renderOption);


Chapter2::Chapter2()
: Lesson("Chapter2")
{
}


void Chapter2::render(double currentTime)
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

    if (m_option == RenderOptionE::POINT)
    {
        glDrawArrays(GL_POINTS, 0, 1);
    }

    else
    {
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}


void Chapter2::startup()
{
    m_option =  RenderOptionE::TRIANGLE;
    glPointSize(40.0f);
    m_program = CreateProgram(m_option);
    glGenVertexArrays(1, &m_vao);
}


void Chapter2::shutdown()
{
    glDeleteProgram(m_program);
    glDeleteVertexArrays(1, &m_vao);
}


static GLuint CreateProgram(RenderOptionE renderOption)
{
    const char *v_str;

    if (renderOption == RenderOptionE::POINT)
    {
        v_str = "#version 430 core\n"
        "void main(void){"
        "gl_Position=vec4(0.0f, 0.0f, 0.5f, 1.0f);"
        "}";
    }

    else 
    {
        v_str = "#version 430 core\n"
        "const vec4 verts[3] = vec4[3](\
            vec4(-0.5f, -0.5f, 0.5f, 1.0f),\
            vec4(0.5f, -0.5f, 0.5f, 1.0f),\
            vec4(0.0f, 0.5f, 0.5f, 1.0f));"
        "void main(void){"
        "gl_Position=verts[gl_VertexID];"
        "}";
    }

    static const GLchar *vertex_src[]=
    {
        v_str
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
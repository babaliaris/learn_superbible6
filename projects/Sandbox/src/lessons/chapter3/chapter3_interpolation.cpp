#include "chapter3_interpolation.h"
#include <vmath.h>

static GLuint CreateProgram();

Chapter3_Interpolation::Chapter3_Interpolation()
:Lesson("Chapter3_Interpolation")
{
}

void Chapter3_Interpolation::render(double currentTime)
{
    const GLfloat clearColor[] = {0.0f, 0.0f, 0.0f, 1.0f};

    //Clear the color buffer.
    glClearBufferfv(GL_COLOR, 0, clearColor);

    //Use program & Bind VAO
    glUseProgram(m_program);
    glBindVertexArray(m_vao);

    //Draw Call.
    glDrawArrays(GL_TRIANGLES, 0, 3);
}


void Chapter3_Interpolation::startup()
{
    m_program = CreateProgram();
    glGenVertexArrays(1, &m_vao);
}


void Chapter3_Interpolation::shutdown()
{
    glDeleteProgram(m_program);
    glDeleteVertexArrays(1, &m_vao);
}


static GLuint CreateProgram()
{
    static const GLchar *vertex_src[]=
    {
        "#version 430 core\n"

        "const vec4 verts[3] = vec4[3](\
            vec4(-0.5f, -0.5f, 0.5f, 1.0f),\
            vec4(0.5f, -0.5f, 0.5f, 1.0f),\
            vec4(0.0f, 0.5f, 0.5f, 1.0f));"

        "const vec4 colors[3] = vec4[3](\
            vec4(1.0f, 0.0f, 0.0f, 1.0f),\
            vec4(0.0f, 1.0f, 0.0f, 1.0f),\
            vec4(0.0f, 0.0f, 1.0f, 1.0f));"

        "out vec4 m_Color;"

        "void main(void)"
        "{"
            "gl_Position=verts[gl_VertexID];"
            "m_Color=colors[gl_VertexID];"
        "}"
    };


    static const GLchar *fragment_src[]=
    {
        "#version 430 core\n"

        "in  vec4 m_Color;"
        "out vec4 m_FragColor;"

        "void main(void)"
        "{"
            "m_FragColor=m_Color;"
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
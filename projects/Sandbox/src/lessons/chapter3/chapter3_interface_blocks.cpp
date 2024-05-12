#include "chapter3_interface_blocks.h"
#include <vmath.h>

static GLuint CreateProgram();

Chapter3_InterfaceBlocks::Chapter3_InterfaceBlocks()
:Lesson("Chapter3_InterfaceBlocks")
{
}

void Chapter3_InterfaceBlocks::render(double currentTime)
{
    const GLfloat clearColor[] = {0.0f, 0.0f, 0.0f, 1.0f};

    const GLfloat animatedColor[] = 
    {
        (float)sin(currentTime) * 0.5f + 0.5f,
        (float)cos(currentTime) * 0.5f + 0.5f,
        0.0f, 1.0f
    };

    const GLfloat offset[] = 
    {
        (float)sin(currentTime) * 0.5f,
        (float)cos(currentTime) * 0.6f,
        0.0f, 0.0f
    };

    //Clear the color buffer.
    glClearBufferfv(GL_COLOR, 0, clearColor);

    //Use program & Bind VAO
    glUseProgram(m_program);
    glBindVertexArray(m_vao);

    
    glVertexAttrib4fv(0, offset); //Update the offset attribute in the vertex shader.
    glVertexAttrib4fv(1, animatedColor); //Update the color attribute in the vertex shader.

    //Draw Call.
    glDrawArrays(GL_TRIANGLES, 0, 3);
}


void Chapter3_InterfaceBlocks::startup()
{
    glPointSize(40.0f);
    m_program = CreateProgram();
    glGenVertexArrays(1, &m_vao);
}


void Chapter3_InterfaceBlocks::shutdown()
{
    glDeleteProgram(m_program);
    glDeleteVertexArrays(1, &m_vao);
}


static GLuint CreateProgram()
{
    static const GLchar *vertex_src[]=
    {
        "#version 430 core\n"
        "layout(location=0) in vec4 a_Offset;"
        "layout(location=1) in vec4 a_Color;"

        "out VS_OUT{" //Interface block. The name VS_OUT must MATCH the next shader in interface block.
        "vec4 color;"
        "}out_color;" //the instantiated variable can have different names in each shader stage.

        "const vec4 verts[3] = vec4[3](\
            vec4(-0.5f, -0.5f, 0.5f, 1.0f),\
            vec4(0.5f, -0.5f, 0.5f, 1.0f),\
            vec4(0.0f, 0.5f, 0.5f, 1.0f));"

        "void main(void){"
        "gl_Position=verts[gl_VertexID] + a_Offset;"
        "out_color.color = a_Color;"
        "}"
    };


    static const GLchar *fragment_src[]=
    {
        "#version 430 core\n"
        "in VS_OUT{" //Interface block. The name VS_OUT must MATCH the next shader in interface block.
        "vec4 color;"
        "}in_color;" //the instantiated variable can have different names in each shader stage.

        "out vec4 m_FragColor;"
        "void main(void){"
        "m_FragColor=in_color.color;"
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
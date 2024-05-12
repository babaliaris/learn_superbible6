#pragma once
#include <sb6.h>
#include <core/lesson.h>

class Chapter3_VertexAttrib4fv : public Lesson
{
    public:
    Chapter3_VertexAttrib4fv();
    
    virtual ~Chapter3_VertexAttrib4fv() = default;
    
    void render(double currentTime) override;
    
    void startup() override;

    void shutdown() override;

    private:
    GLuint m_program, m_vao;
};
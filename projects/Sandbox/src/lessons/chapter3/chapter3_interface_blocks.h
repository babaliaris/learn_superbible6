#pragma once
#include <sb6.h>
#include <core/lesson.h>

class Chapter3_InterfaceBlocks : public Lesson
{
    public:
    Chapter3_InterfaceBlocks();
    
    virtual ~Chapter3_InterfaceBlocks() = default;
    
    void render(double currentTime) override;
    
    void startup() override;

    void shutdown() override;

    private:
    GLuint m_program, m_vao;
};
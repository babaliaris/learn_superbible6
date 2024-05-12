#pragma once
#include <lessons/chapter2/chapter2.h>
#include <lessons/chapter3/chapter3_VertexAttrib4fv.h>

enum class LessonE
{
    CHAPTER2,
    CHAPTER3_VERTEX_ATTRIB4FV
};

Lesson *GetLesson(LessonE lesson)
{
    switch (lesson)
    {
        case LessonE::CHAPTER2:
            return new Chapter2();

        case LessonE::CHAPTER3_VERTEX_ATTRIB4FV:
            return new Chapter3_VertexAttrib4fv();
        
        default:
            printf("[GetLesson()] Uknown Lesson.");
            return nullptr;
    }
}
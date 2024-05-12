#pragma once
#include <lessons/chapter2/chapter2.h>

enum class LessonE
{
    CHAPTER2
};

Lesson *GetLesson(LessonE lesson)
{
    switch (lesson)
    {
        case LessonE::CHAPTER2:
            return new Chapter2();
        
        default:
            printf("[GetLesson()] Uknown Lesson.");
            return nullptr;
    }
}
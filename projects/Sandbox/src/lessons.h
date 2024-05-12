#pragma once
#include <lessons/chapter2/chapter2.h>
#include <lessons/chapter3/chapter3_VertexAttrib4fv.h>
#include <lessons/chapter3/chapter3_passing_data_from_stage_to_stage.h>

enum class LessonE
{
    CHAPTER2,
    CHAPTER3_VERTEX_ATTRIB4FV,
    CHAPTER3_PASSING_DATA_FROM_STAGE_TO_STAGE

};

Lesson *GetLesson(LessonE lesson)
{
    switch (lesson)
    {
        case LessonE::CHAPTER2:
            return new Chapter2();

        case LessonE::CHAPTER3_VERTEX_ATTRIB4FV:
            return new Chapter3_VertexAttrib4fv();

        case LessonE::CHAPTER3_PASSING_DATA_FROM_STAGE_TO_STAGE:
            return new Chapter3_PassingDataFromStageToStage();
        
        default:
            printf("[GetLesson()] Uknown Lesson.");
            return nullptr;
    }
}
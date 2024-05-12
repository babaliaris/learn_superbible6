#pragma once
#include <lessons/chapter2/chapter2.h>
#include <lessons/chapter3/chapter3_VertexAttrib4fv.h>
#include <lessons/chapter3/chapter3_passing_data_from_stage_to_stage.h>
#include <lessons/chapter3/chapter3_interface_blocks.h>
#include <lessons/chapter3/chapter3_fragment_shader.h>
#include <lessons/chapter3/chapter3_interpolation.h>

enum class LessonE
{
    CHAPTER2,
    CHAPTER3_VERTEX_ATTRIB4FV,
    CHAPTER3_PASSING_DATA_FROM_STAGE_TO_STAGE,
    CHAPTER3_INTERFACE_BLOCKS,
    CHAPTER3_FRAGMENT_SHADER,
    CHAPTER3_INTERPOLATION

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

        case LessonE::CHAPTER3_INTERFACE_BLOCKS:
            return new Chapter3_InterfaceBlocks();

        case LessonE::CHAPTER3_FRAGMENT_SHADER:
            return new Chapter3_FragmentShader();

        case LessonE::CHAPTER3_INTERPOLATION:
            return new Chapter3_Interpolation();
        
        default:
            printf("[GetLesson()] Uknown Lesson.");
            return nullptr;
    }
}
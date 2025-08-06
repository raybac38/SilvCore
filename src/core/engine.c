#include "core/engine.h"

#include "system/transformSystem.h"
#include "system/renderSystem.h"

void engine_init(){
    transform_system_init();
}

void engine_run(){

}

void engine_clean(){
    transform_system_clean();
}


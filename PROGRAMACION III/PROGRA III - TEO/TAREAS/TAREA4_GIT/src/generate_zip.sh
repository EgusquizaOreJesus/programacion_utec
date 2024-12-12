#!/usr/bin/env bash

project_name='prog3_complejidad_algoritmica_v2022_1'
source_code='
        sp4.h sp4.cpp
  '
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}
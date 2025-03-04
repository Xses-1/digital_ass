#!/bin/bash

tar cvf - ../ass3 | ssh tomato 'tar xf -'

#!/bin/sh

podman run --rm -v ./:/pwd armtoolchain "$@"


# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build & Run

```bash
gcc -o process_demo process_demo.c
./process_demo
```

## Overview

Single-file C program (`process_demo.c`) demonstrating Unix process concepts:
- `fork()` - creates a child process
- Zombie process state - child exits before parent calls `wait()`
- `wait()` - parent reaps child process

The program pauses at two points to allow observation of the zombie state before and after reaping.

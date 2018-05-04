#pragma once

#define DISALLOW_COPY_AND_ASSIGN(TypeName)    \
    TypeName(const TypeName&) = delete;       \
    void operator=(const TypeName&) = delete

#define DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName)  \
    TypeName() = delete;                          \
    DISALLOW_COPY_AND_ASSIGN(TypeName)

#ifndef FUNNYEGG_SHAPES_H
#define FUNNYEGG_SHAPES_H

namespace Shapes
{
    namespace Vertex
    {
        float TRIANGLE[] = {
                0.5f, 0.5f,
                0.5f, -0.5f,
                -0.5f, -0.5f
        };

        float QUAD[] = {
                -0.5, 0.5, // top left
                0.5, 0.5, // top right
                0.5, -0.5, // bottom right
                -0.5, -0.5 // bottom left
        };

        float TRIFORCE[] = {
            // TOP TRIANGLE
            0.0f, 0.5f,
            0.25f, 0.0f,
            -0.25f, 0.0f,
            0.5, -0.5f,
            0.0, -0.5f,
            -0.5f, -0.5f,
        };
    }

    namespace Index
    {
        unsigned int QUAD[] = {
            0, 1, 3,
            1, 2, 3
        };

        unsigned int TRIFORCE[] = {
            0, 1, 2,
            1, 3, 4,
            2, 4, 5,
        };
    }
};

#endif //FUNNYEGG_SHAPES_H

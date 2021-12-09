#define _EXERCIZE

#ifdef _EXERCIZE
#include"libOne.h"
void gmain() {
    window(1400, 700);

    const int numVertices = 4;
    VECTOR op[numVertices] = {
        VECTOR(-0.5f,0.5f,0),
        VECTOR(-0.5f,-0.5f,0),
        VECTOR(0.5f,-0.5f,0),
        VECTOR(0.5f,0.5f,0),
    };
    //座標変換後の位置
    VECTOR p[numVertices];

    MATRIX world, view, proj;
    float angleX = 0;
    float angleY = 0;
    float radius = 3;
    while (notQuit) {

        clear(60);
        world.identity();
        world.mulRotateX(-1.57f);
        VECTOR camPos, lookat(0, 0, 0), up(0, 1, 0);
        if (isPress(KEY_L)) { angleY += 0.017f; }
        if (isPress(KEY_J)) { angleY -= 0.017f; }
        if (isPress(KEY_I)) { angleX += 0.017f; }
        if (isPress(KEY_K)) { angleX -= 0.017f; }
        camPos.x = sin(angleY) * cos(angleX)* radius;
        camPos.y =               sin(angleX) * radius;
        camPos.z = cos(angleY) * cos(angleX) * radius;
        view.camera(camPos,lookat,up);
        //proj
        float fov = 3.14f / 2;
        float aspect = width / height;
        float near_ = 1;
        float far_ = 100;
        proj.pers(fov, aspect,near_,far_);

        for (int i = 0; i < numVertices; i++) {
            //world座標変換
            p[i] = world * op[i];
            //view座標変換・プレイヤーの視点
            p[i] = view * p[i];
            //projection座標変換
            p[i] = proj * p[i];

        }
        triangle3D(p[0], p[1], p[2]);
        triangle3D(p[0], p[2], p[3]);

    }
}
#endif

#ifdef _3D_ROTATE
#include"libOne.h"
void gmain() {
    window(800, 800);

    const int numVertices = 4;
    VECTOR op[numVertices] = {
        VECTOR(-0.5f,0.5f,0),
        VECTOR(-0.5f,-0.5f,0),
        VECTOR(0.5f,-0.5f,0),
        VECTOR(0.5f,0.5f,0),
    };
    VECTOR p[numVertices];

    float theta = 0;
    float c =0;
    float s =0;

    int swch = 0;

    while (notQuit) {

        clear(60);
        theta += 0.017f;
        c = cos(theta);
        s = sin(theta);
        if (isTrigger(KEY_SPACE)) {
            ++swch %= 3;
        }
        for (int i = 0; i < numVertices; i++) {
            //world座標変換
            if (swch == 0) {
                p[i].x = c * op[i].x - s * op[i].y;
                p[i].y = s * op[i].x + c * op[i].y;
                p[i].z = op[i].z;
            }
            if (swch == 1) {
                p[i].x = c * op[i].x - s * op[i].z;
                p[i].y = op[i].y;
                p[i].z = s * op[i].x + c * op[i].z;
            }
            if (swch == 2) {
                p[i].x =op[i].x;
                p[i].y = c * op[i].y - s * op[i].z;
                p[i].z = s * op[i].y + c * op[i].z;
            }
            p[i].z = op[i].z - 2;
            //projection座標変換
            p[i].z *= -1;
            p[i].x /= p[i].z;
            p[i].y /= p[i].z;
            p[i].z /= p[i].z;

        }
        triangle3D(p[0], p[1], p[2]);
        triangle3D(p[0], p[2], p[3]);

    }
}
#endif

#ifdef _3D_COORDINATE
#include"libOne.h"
void gmain() {
    window(800,800);
    VECTOR p[3] = {
        VECTOR(-1,1,1),
        VECTOR(-1,-1,1),
        VECTOR(1,-1,1),
    };

    while (notQuit) {

        clear(60);
        triangle3D(p[0], p[1], p[2]);

    }
}
#endif

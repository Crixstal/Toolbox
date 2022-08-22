#include <cassert>

#include "maths.hpp"

void TestVector2()
{
    // Length
    assert(Vector2(3.f, 4.f).Length() == 5.f);
    assert(Vector2(-3.f, 4.f).Length() == 5.f);
    assert(Vector2(3.f, -4.f).Length() == 5.f);
    assert(Vector2(-3.f, -4.f).Length() == 5.f);


    std::cout << "TESTS ON VECTOR 2 OK" << "\n";
}

void TestVector3()
{
    // Dot Product
    assert(Vector3::DotProduct(Vector3(8.f, 5.f, 1.f), Vector3(6.f, 8.f, 3.f)) == 91.f);
    assert(Vector3::DotProduct(Vector3(8.f, -7.f, 1.f), Vector3(6.f, 8.f, 3.f)) == -5.f);
    assert(Vector3::DotProduct(Vector3(8.f, 7.f, 1.f), Vector3(4.f, 8.f, -3.f)) == 85.f);
    assert(Vector3::DotProduct(Vector3(8.f, -7.f, 1.f), Vector3(-4.f, 8.f, 3.f)) == -85.f);

    // Cross Product
    assert(Vector3::CrossProduct(Vector3(8.f, 5.f, 1.f), Vector3(6.f, 8.f, 3.f)) == Vector3(7.f, -18.f, 34.f));
    assert(Vector3::CrossProduct(Vector3(8.f, -7.f, 1.f), Vector3(6.f, 8.f, 3.f)) == Vector3(-29.f, -18.f, 106.f));
    assert(Vector3::CrossProduct(Vector3(8.f, 7.f, 1.f), Vector3(4.f, 8.f, -3.f)) == Vector3(-29.f, 28.f, 36.f));
    assert(Vector3::CrossProduct(Vector3(8.f, -7.f, 1.f), Vector3(-4.f, 8.f, 3.f)) == Vector3(-29.f, -28.f, 36.f));

    // Vector from point
    assert(Vector3::VecFromPt(Vector3(8.f, 9.f, 4.f), Vector3(2.f, 0.f, 5.f)) == Vector3(-6.f, -9.f, 1.f));
    assert(Vector3::VecFromPt(Vector3(-8.f, 9.f, 4.f), Vector3(2.f, 0.f, 5.f)) == Vector3(10.f, -9.f, 1.f));
    assert(Vector3::VecFromPt(Vector3(8.f, 9.f, 4.f), Vector3(2.f, 0.f, -5.f)) == Vector3(-6.f, -9.f, -9.f));
    assert(Vector3::VecFromPt(Vector3(8.f, -9.f, 4.f), Vector3(-2.f, 0.f, -5.f)) == Vector3(-10.f, 9.f, -9.f));

    // Length
    assert(Vector3(8.f, 2.f, 4.f).Length() == Maths::Sqrt(84.f));
    assert(Vector3(-8.f, 2.f, 4.f).Length() == Maths::Sqrt(84.f));
    assert(Vector3(8.f, -2.f, 4.f).Length() == Maths::Sqrt(84.f));
    assert(Vector3(8.f, 2.f, -4.f).Length() == Maths::Sqrt(84.f));
    assert(Vector3(-8.f, -2.f, -4.f).Length() == Maths::Sqrt(84.f));

    // Square Length
    assert(Vector3(8.f, 2.f, 4.f).SqrLength() == 84.f);
    assert(Vector3(-8.f, 2.f, 4.f).SqrLength() == 84.f);
    assert(Vector3(8.f, -2.f, 4.f).SqrLength() == 84.f);
    assert(Vector3(8.f, 2.f, -4.f).SqrLength() == 84.f);
    assert(Vector3(-8.f, -2.f, -4.f).SqrLength() == 84.f);

    // Distance
    assert(Vector3::Distance(Vector3(8.f, 6.f, 7.f), Vector3(3.f, 5.f, 2.f)) == Maths::Sqrt(51.f));
    assert(Vector3::Distance(Vector3(8.f, -6.f, 7.f), Vector3(3.f, 5.f, 2.f)) == Maths::Sqrt(171.f));
    assert(Vector3::Distance(Vector3(8.f, 6.f, 7.f), Vector3(-3.f, 5.f, 2.f)) == Maths::Sqrt(147.f));
    assert(Vector3::Distance(Vector3(8.f, -6.f, 7.f), Vector3(-3.f, 5.f, -2.f)) == Maths::Sqrt(323.f));

    // Rotate by Quaternion
    assert(Vector3::RotateByQuat(Vector3(1.f, 0.f, 0.f), Quaternion(0.f, 0.f, 0.707107f, 0.707107f)) == Vector3(0.f, 1.f, 0.f));


    std::cout << "TESTS ON VECTOR 3 OK" << "\n";
}

void TestVector4()
{
    // Length
    assert(Vector4(8.f, 6.f, 4.f, 3.f).Length() == Maths::Sqrt(125.f));
    assert(Vector4(-6.f, 2.f, 4.f, 8.f).Length() == Maths::Sqrt(120.f));
    assert(Vector4(6.f, -2.f, 4.f, 8.f).Length() == Maths::Sqrt(120.f));
    assert(Vector4(6.f, 2.f, -4.f, 8.f).Length() == Maths::Sqrt(120.f));
    assert(Vector4(6.f, 2.f, 4.f, -8.f).Length() == Maths::Sqrt(120.f));
    assert(Vector4(-4.f, -2.f, -7.f, -6.f).Length() == Maths::Sqrt(105.f));


    std::cout << "TESTS ON VECTOR 4 OK" << "\n";
}

void TestQuaternion()
{
    std::cout << "\n////////////////////////////// QUATERNION" << "\n\n";

    Quaternion test_constructor1;
    Quaternion test_constructor2(1.f, 2.f, 3.f, 4.f);

    Quaternion quat(0.f, 1.f, 0.f, 1.f);

    Matrix4 mat = {
            0.f, 0.f, 1.f, 0.f,
            0.f, 1.f, 0.f, 0.f,
            -1.f, 0.f, 0.f, 0.f,
            0.f, 0.f, 0.f, 0.f
    };
    Quaternion quatMat = Quaternion::QuatFromMatrix(mat);
    Quaternion quatFromEuler = Quaternion::QuatFromEuler(0.f, Maths::Constants::pi, 0.f);
    Vector3 quatToEuler = quat.QuatToEuler();
    Quaternion quatFromAxis = Quaternion::QuatFromAxisAngle(Vector3(0.f, 1.f, 0.f), Maths::Constants::halfPi);

    Vector3 vec = Vector3::zero;
    float axis = 0.f;
    quat.QuatToAxisAngle(vec, axis);

    Quaternion qStart = Quaternion(0.f, 0.f, 0.f, 1.f);
    Quaternion qEnd = Quaternion(0.f, 1.f, 0.f, 1.f);
    qEnd = qEnd.Normalize();
    Quaternion qLerp = quat.Lerp(qStart, qEnd, 0.5f);
    Quaternion qNLerp = quat.Nlerp(qStart, qEnd, 0.5f);
    Quaternion qSLerp = quat.Slerp(qStart, qEnd, 0.5f);

#ifdef LOG_TEST
    std::cout << "test_constructor1 : " << test_constructor1 << '\n';
    std::cout << "test_constructor2 : " << test_constructor2 << '\n';
    std::cout << "test_identity : " << Quaternion::Identity() << '\n';

    std::cout << std::endl << "example quaternion : " << quat << std::endl;
    std::cout << "test_normalize : " << quat.Normalize() << '\n';
    std::cout << "test_length : " << quat.Length() << '\n';
    std::cout << "test_invert : " << quat.Invert() << '\n';

    std::cout << "\ntest_fromMat : " << quatMat << '\n';
    std::cout << "test_fromEuler : " << quatFromEuler << '\n';
    std::cout << "test_toEuler : " << quatToEuler << '\n';
    std::cout << "test_fromAxis : " << quatFromAxis << '\n';
    std::cout << "test_toAxis : " << "vec = " << vec << " / axis = " << axis << '\n';

    std::cout << "\nstarting quaternion : " << qStart << '\n';
    std::cout << "Ending quaternion : " << qEnd << '\n';
    std::cout << "test_lerp : " << qLerp << '\n';
    std::cout << "test_Nlerp : " << qNLerp << '\n';
    std::cout << "test_Slerp : " << qSLerp << '\n';
#endif

#ifdef LOG_ASSERTION
    if (quat.Normalize() != Quaternion(0.f, 0.7071067811865475f, 0.f, 0.7071067811865475f))
        std::cout << "ERROR : Quaternion normalization is not correct" << std::endl;
    if (quat.Invert() != Quaternion(0.f, -0.5f, 0.f, 0.5f))
        std::cout << "ERROR : Quaternion inversion is not correct" << std::endl;

    if (quatMat != Quaternion(0.f, 0.707107, 0.f, 0.707107f))
        std::cout << "ERROR : Quaternion from Matrix is not correct" << std::endl;
    if (quatFromEuler != Quaternion(0.f, 1.f, 0.f, 0.f))
        std::cout << "ERROR : Quaternion from Euler is not correct" << std::endl;
    if (quatToEuler != Vector3(3.141595123321442f, 1.5707963057214724f, 3.141595123321442f))
        std::cout << "ERROR : Quaternion to Euler is not correct" << std::endl;
    if (quatFromAxis != Quaternion(0.f, 0.707107, 0.f, 0.707107))
        std::cout << "ERROR : Quaternion from Axis-Angle is not correct" << std::endl;
    if (vec != Vector3(0.f, 1.f, 0.f) || axis != 0.f)
        std::cout << "ERROR : Quaternion to Axis-Angle is not correct" << std::endl;

    if (qSLerp != Quaternion(0.f, 0.38268352626028224f, 0.f, 0.9238795917217785f))
        std::cout << "ERROR : SLerp is not correct" << std::endl;
#endif

    std::cout << "TESTS ON QUATERNION OK" << "\n";
}

void TestMatrix4()
{
    Matrix4 mat1 = {
            2.f, 8.f, 7.f, 8.f,
            -1.f, 2.f, 0.f, 1.f,
            1.f, 4.f, 0.f, -5.f,
            6.f, 3.f, 0.f, 1.f
    };

    Matrix4 mat2 = {
            5.f, 7.f, 0.f, -7.f,
            1.f, 5.f, 4.f, -2.f,
            0.f, 7.f, 1.f, 9.f,
            7.f, 4.f, 3.f, 6.f
    };

    // Transpose
    assert(mat1.Transpose() == Matrix4(2.f, -1.f, 1.f, 6.f,
                                       8.f, 2.f, 4.f, 3.f,
                                       7.f, 0.f, 0.f, 0.f,
                                       8.f, 1.f, -5.f, 1.f));

    // Inverse
    assert(mat1.Inverse() == Matrix4(0.f,       (-19.f/102.f),  (-1.f/102.f),   (7.f/51.f),
                                     0.f,       (31.f/102.f),   (7.f/102.f),    (2.f/51.f),
                                     (1.f/7.f), (-9.f/17.f),    (11.f/119.f),   (-18.f/119.f),
                                     0.f,       (7.f/34.f),     (-5.f/34.f),    (1.f/17.f)));

    // Multiplication
    assert(mat1 * mat2 == Matrix4(74.f,  135.f, 63.f,  81.f,
                                  4.f,   7.f,   11.f,  9.f,
                                  -26.f, 7.f,   1.f,  -45.f,
                                  40.f,  61.f,  15.f, -42.f));

    // Frustum
    // TODO Create a test for Matrix4::Frustum()

    // Orthographic
    // TODO Create a test for Matrix4::Orthographic()

    // Perspective
    // TODO Create a test for Matrix4::Perspective()

    // Rotate X
    assert(Matrix4::RotateX(Maths::Constants::pi/4) == Matrix4(1.f, 0.f,                  0.f,                   0.f,
                                                               0.f, 1.f/Maths::Sqrt(2.f), -1.f/Maths::Sqrt(2.f), 0.f,
                                                               0.f, 1.f/Maths::Sqrt(2.f), 1.f/Maths::Sqrt(2.f),  0.f,
                                                               0.f, 0.f,                  0.f,                   1.f));

    // Rotate Y
    assert(Matrix4::RotateY(Maths::Constants::pi/4) == Matrix4(1.f/Maths::Sqrt(2.f),  0.f, 1.f/Maths::Sqrt(2.f), 0.f,
                                                               0.f,                   1.f, 0.f,                  0.f,
                                                               -1.f/Maths::Sqrt(2.f), 0.f, 1.f/Maths::Sqrt(2.f), 0.f,
                                                               0.f,                   0.f, 0.f,                  1.f));

    // Rotate Z
    assert(Matrix4::RotateZ(Maths::Constants::pi/4) == Matrix4(1.f/Maths::Sqrt(2.f), -1.f/Maths::Sqrt(2.f), 0.f, 0.f,
                                                               1.f/Maths::Sqrt(2.f), 1.f/Maths::Sqrt(2.f),  0.f, 0.f,
                                                               0.f,                  0.f,                   1.f, 0.f,
                                                               0.f,                  0.f,                   0.f, 1.f));

    // Rotate ZYX
    assert(Matrix4::RotateZYX(Maths::Constants::halfPi, Maths::Constants::halfPi, Maths::Constants::halfPi) == Matrix4(0.f, 0.f, 1.f, 0.f,
                                                                                                                       0.f, 1.f, 0.f, 0.f,
                                                                                                                       -1.f, 0.f, 0.f, 0.f,
                                                                                                                       0.f, 0.f, 0.f, 1.f));

    // Matrix from Quaternion
    // TODO Create a test for Matrix4::MatrixFromQuat()

    // Translate
    assert(Matrix4::Translate(5.f, -8.f, 2.f) == Matrix4(1.f, 0.f, 0.f, 0.f,
                                                         0.f, 1.f, 0.f, 0.f,
                                                         0.f, 0.f, 1.f, 0.f,
                                                         5.f, -8.f, 2.f, 1.f));

    assert(Matrix4::Translate(Vector3(6.f, 4.f, -3.f)) == Matrix4(1.f, 0.f, 0.f, 0.f,
                                                                  0.f, 1.f, 0.f, 0.f,
                                                                  0.f, 0.f, 1.f, 0.f,
                                                                  6.f, 4.f, -3.f, 1.f));

    // Scale
    assert(Matrix4::Scale(5.f) == Matrix4(5.f, 0.f, 0.f, 0.f,
                                          0.f, 5.f, 0.f, 0.f,
                                          0.f, 0.f, 5.f, 0.f,
                                          0.f, 0.f, 0.f, 1.f));

    assert(Matrix4::Scale(Vector3(6.f, 4.f, -3.f)) == Matrix4(6.f, 0.f, 0.f, 0.f,
                                                              0.f, 4.f, 0.f, 0.f,
                                                              0.f, 0.f, -3.f, 0.f,
                                                              0.f, 0.f, 0.f, 1.f));

    // TODO Create a test for Matrix4::LookAt()

    std::cout << "TESTS ON MATRIX 4 OK" << "\n";
}

int main()
{
    TestVector2();
    TestVector3();
    TestVector4();
    //TestQuaternion();
    TestMatrix4();

    return 0;
}
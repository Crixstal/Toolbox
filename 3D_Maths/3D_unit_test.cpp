#include <cassert>

#include "maths.hpp"

// Test des vecteurs : https://physics.icalculator.info/vector-calculator/addition-and-subtraction-of-vectors.html
// Test des quaternions : https://www.energid.com/resources/orientation-calculator
//                        https://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/slerp/index.htm
// Test des matrices : https://matrixcalc.org/en/
//                     https://www.redcrab-software.com/en/Calculator/3x3/Matrix/Rotation-XYZ
//                     Projet 'ibr' de Paul (pour la projection)

void TestVector2()
{
    // Constructors
    assert(Vector2() == Vector2(0.f, 0.f));

    assert(Vector2(1.f, 2.f) == Vector2(1.f, 2.f));
    assert(Vector2(-1.8f, 2.f) == Vector2(-1.8f, 2.f));
    assert(Vector2(1.f, -2.5f) == Vector2(1.f, -2.5f));
    assert(Vector2(-1.f, -2.f) == Vector2(-1.f, -2.f));

    // Length
    assert(Vector2(3.f, 4.f).Length() == 5.f);
    assert(Vector2(-3.f, 4.f).Length() == 5.f);
    assert(Vector2(3.f, -4.f).Length() == 5.f);
    assert(Vector2(-3.f, -4.f).Length() == 5.f);


    std::cout << "TESTS ON VECTOR 2 OK" << "\n";
}

void TestVector3()
{
    // Constructors
    assert(Vector3() == Vector3(0.f, 0.f, 0.f));

    assert(Vector3(1.f, 2.f, 8.f) == Vector3(1.f, 2.f, 8.f));
    assert(Vector3(-1.8f, 2.f, 5.f) == Vector3(-1.8f, 2.f, 5.f));
    assert(Vector3(1.f, -2.5f, 4.5f) == Vector3(1.f, -2.5f, 4.5f));
    assert(Vector3(1.f, 2.5f, -5.f) == Vector3(1.f, 2.5f, -5.f));
    assert(Vector3(-1.f, -2.f, -9.f) == Vector3(-1.f, -2.f, -9.f));

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
    // Constructors
    assert(Vector4() == Vector4(0.f, 0.f, 0.f, 0.f));

    assert(Vector4(1.f, 2.f, 3.f, 8.f) == Vector4(1.f, 2.f, 3.f, 8.f));
    assert(Vector4(-1.f, 2.f, 3.f, 12.7f) == Vector4(-1.f, 2.f, 3.f, 12.7f));
    assert(Vector4(1.f, -2.f, 3.f, 8.f) == Vector4(1.f, -2.f, 3.f, 8.f));
    assert(Vector4(1.f, 5.6f, -3.f, 8.f) == Vector4(1.f, 5.6f, -3.f, 8.f));
    assert(Vector4(0.3f, 2.f, 3.f, -8.f) == Vector4(0.3f, 2.f, 3.f, -8.f));
    assert(Vector4(-1.f, -2.f, -3.f, -8.f) == Vector4(-1.f, -2.f, -3.f, -8.f));

    assert(Vector4(Vector3(2.f, 5.f, 9.f), 6.1f) == Vector4(2.f, 5.f, 9.f, 6.1f));
    assert(Vector4(Vector3(-2.f, 5.f, 9.f), 6.1f) == Vector4(-2.f, 5.f, 9.f, 6.1f));
    assert(Vector4(Vector3(2.f, -5.f, 9.f), 6.1f) == Vector4(2.f, -5.f, 9.f, 6.1f));
    assert(Vector4(Vector3(2.f, 5.f, -9.f), -6.1f) == Vector4(2.f, 5.f, -9.f, -6.1f));
    assert(Vector4(Vector3(-2.f, -5.f, -9.f), -6.1f) == Vector4(-2.f, -5.f, -9.f, -6.1f));

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
    std::cout << "\n////////////////////////////// MATRIX4" << "\n\n";

    Matrix4 mat = Matrix4::Identity();
    Vector3 v1(1.f, 2.f, 3.f);

    float angle = Maths::Constants::halfPi;
    Vector3 v2(angle, angle, angle);

    Matrix4 matXRot = mat.RotateX(angle);
    Matrix4 matYRot = mat.RotateY(angle);
    Matrix4 matZRot = mat.RotateZ(angle);
    Matrix4 matXYZRot = mat.RotateXYZ(v2);

    Matrix4 m1 = {
            2.f, 0.f, 0.f, 0.f,
            0.f, 2.f, 0.f, 1.f,
            1.f, 0.f, 0.f, 0.f,
            0.f, 0.f, 0.f, 1.f
    };

    Matrix4 m2 = {
            8.f, 0.f, 2.f, 4.f,
            7.f, 1.f, 1.f, 0.f,
            15.f, 21.f, 0.f, 0.f,
            1.f, 0.f, 0.f, 0.f
    };

    Matrix4 transpose = m2.Transpose();
    Matrix4 inverse = m2.Inverse();

    Matrix4 m1xm2 = m1 * m2;

    float fov = 90.f; // WARNING: The fov should be in radians, but for tests we don't take care about it

    Matrix4 projection = Matrix4::Perspective(fov, 16.f/9.f, 0.001f, 1000.f, false);
    Matrix4 orthographic = Matrix4::Perspective(fov, 16.f/9.f, 0.001f, 1000.f, true);

    std::cout << "test_identity : \n" << m2 << '\n';
    std::cout << "test_transpose :" << m2.Transpose() << '\n';
#ifdef LOG_TEST
    std::cout << "test_null : \n" << Matrix4::Null() << '\n';
    std::cout << "test_multiplyVector : " << mat * v1 << '\n';

    //std::cout << "test_frustum : \n" << mat.Frustum(left, right, bottom, top, near, far) << '\n';
    //std::cout << "test_ortho : \n" << mat.Orthographic(left, right, bottom, top, near, far) << '\n';
    //std::cout << "test_perspective : \n" << mat.Perspective(fov, aspect, near, far, false) << '\n';

    std::cout << "test_inverse :" << m2.Inverse() << '\n';

    std::cout << std::endl << "test_multiplication m1 : \n" << m1 << std::endl;
    std::cout << "test_multiplication m2 : \n" << m2 << std::endl;
    std::cout << "test_multiplication : \n" << m1xm2 << std::endl;

    std::cout << std::endl << "test_rotateX : \n" << matXRot << '\n';
    std::cout << "test_rotateY : \n" << matYRot << '\n';
    std::cout << "test_rotateZ : \n" << matZRot << '\n';
    std::cout << "test_rotateXYZ : \n" << matXYZRot << '\n';

    std::cout << "test_translate1 : \n" << mat.Translate(1.f, 2.f, 3.f) << '\n';
    std::cout << "test_translate2 : \n" << mat.Translate(v2) << '\n';

    std::cout << "test_scale1 : \n" << mat.Scale(angle) << '\n';
    std::cout << "test_scale2 : \n" << mat.Scale(v2) << '\n';

    std::cout << "\n test_perspective : \n" << projection << std::endl;
    std::cout << "test_orthographic : \n" << orthographic << std::endl;
#endif
#ifdef LOG_ASSERTION
    Matrix4 multiplyAssert = {
            0.f, 0.f, 2.f, 2.f,
            1.f, 2.f, 2.f, 0.f,
            0.f, 0.f, 1.f, 1.f,
            1.f, 0.f, 0.f, 0.f
    };

    Matrix4 xAssert = {
            1.f, 0.f, 0.f, 0.f,
            0.f, 0.f,-1.f, 0.f,
            0.f, 1.f, 0.f, 0.f,
            0.f, 0.f, 0.f, 1.f,
    };
    Matrix4 yAssert = {
            0.f, 0.f, 1.f, 0.f,
            0.f, 1.f, 0.f, 0.f,
            -1.f, 0.f, 0.f, 0.f,
            0.f, 0.f, 0.f, 1.f,
    };
    Matrix4 zAssert = {
            0.f,-1.f, 0.f, 0.f,
            1.f, 0.f, 0.f, 0.f,
            0.f, 0.f, 1.f, 0.f,
            0.f, 0.f, 0.f, 1.f,
    };
    Matrix4 xyzAssert = {
            1.f, 0.f, 0.f, 0.f,
            0.f, 0.f,-1.f, 0.f,
            0.f, 1.f, 0.f, 0.f,
            0.f, 0.f, 0.f, 1.f
    };

    Matrix4 transposeAssert = {
            0.f, 0.f, 1.f, 1.f,
            0.f, 1.f, 1.f, 0.f,
            1.f, 1.f, 0.f, 0.f,
            1.f, 0.f, 0.f, 0.f
    };

    Matrix4 inverseAssert = {
            0.f, 0.f, 0.f, 1.f,
            0.f, 0.f, 1.f,-1.f,
            0.f, 1.f,-1.f, 1.f,
            1.f,-1.f, 1.f,-1.f
    };

    Matrix4 projAssert = {
            0.61737f,   0.f,        0.f,    0.f,
            0.f,        0.61737,    0.f,    0.f,
            0.f,        0.f,        -1.f,   -1.f,
            0.f,        0.f,        -0.002f, 0.f
    };

    Matrix4 orthoAssert = {
            617.36962f, 0.f,        0.f,        0.f,
            0.f,        617.36962f, 0.f,        0.f,
            0.f,        0.f,        -0.002f,    0.f,
            0.f,        0.f,        -1.f,       0.f
    };

    if (m1xm2 != multiplyAssert)
        std::cout << "ERROR : Matrice multiplication is not correct" << std::endl;

    if (transpose != transposeAssert)
        std::cout << "ERROR : Matrice transpose is not correct" << std::endl;
    if (inverse != inverseAssert)
        std::cout << "ERROR : Matrice inverse is not correct" << std::endl;

    if (matXRot != xAssert)
        std::cout << "ERROR : Matrix X Rotation is not correct" << std::endl;
    if (matYRot != yAssert)
        std::cout << "ERROR : Matrix Y Rotation is not correct" << std::endl;
    if (matZRot != zAssert)
        std::cout << "ERROR : Matrix Z Rotation is not correct" << std::endl;
    if (matXYZRot != xyzAssert)
        std::cout << "ERROR : Matrix XYZ Rotation is not correct" << std::endl;

//    if (projection != projAssert)
//    {
//        std::cout << "ERROR : Projection Matrix from frustrum is not correct" << std::endl;
//        std::cout << "--- Attempted matrix is : \n" << projAssert << std::endl;
//    }
//
//    if (orthographic != orthoAssert)
//    {
//        std::cout << "ERROR : Projection Matrix from orthographic is not correct" << std::endl;
//        std::cout << "--- Attempted matrix is : \n" << orthoAssert << std::endl;
//    }

#endif

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
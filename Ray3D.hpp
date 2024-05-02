/*
** EPITECH PROJECT, 2024
** B-OOP-400-NAN-4-1-bsraytracer-florent.charpentier
** File description:
** Vector3D
*/

namespace Math {
    class Vector3D;
    class Ray3D {
        public:
            Ray3D();
            Ray3D(const Vector3D &origin, const Vector3D &direction);
            ~Ray3D() = default;
            Vector3D getOrigin() const; // can be a point i think
            Vector3D getDirection() const;
            Vector3D pointOnRay(double t) const; // p(t) = origin + t * direction (a point that move along the ray)

            Vector3D _origin; // can be a point i think
            Vector3D _direction;

        protected:
        private:
    };
}
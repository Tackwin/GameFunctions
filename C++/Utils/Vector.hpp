#pragma once
#include <string>
#include <Box2D\Common\b2Math.h>
#include <SFML\System\Vector2.hpp>

#define PIXL_TO_METER 0.1

class Vector {
public:
	float x;
	float y;

	Vector();
	Vector(std::string &string);
	template<typename T> Vector(sf::Vector2<T> &A);
	Vector(float x = 0, float y = 0);
	~Vector();

	float length() const;
	float length2() const;

	float distTo(const float &x, const float &y) const;
	float distTo(const Vector &A) const;
	float distTo2(const float &x, const float &y) const;
	float distTo2(const Vector &A) const;

	float angleX() const;
	float angleTo(const float &x, const float &y) const;
	float angleTo(const Vector &A) const;

	void normalize(float length = 1.f);
	
	void rotate(float rad);
	void rotate90();
	
	void print(const std::string pre = "", const std::string sui = "");
	void readFromString(std::string &string);
	void writetoString(std::string *string);

	Vector& operator=(const Vector &A);

	Vector operator+(const Vector &A) const;
	Vector& operator+=(const Vector &A);

	Vector operator-(const Vector &A) const;
	Vector& operator-=(const Vector &A);

	Vector operator*(const Vector &A) const;
	Vector& operator*=(const Vector &A);
	
	Vector operator/(const Vector &A) const;
	Vector& operator/=(const Vector &A);

	bool operator==(const Vector &A) const;
	bool operator!=(const Vector &A) const;
	bool operator>(const Vector &A) const;
	bool operator>=(const Vector &A) const;
	bool operator<(const Vector &A) const;
	bool operator<=(const Vector &A) const;

	template<typename T> operator sf::Vector2<T>();
	operator b2Vec2();
};

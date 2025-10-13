//Mariia Nyzhnyk grupa 1.4.8

#pragma once
#include <iostream>

class UMeshComponent
{
public:
	UMeshComponent()
	{

	}
	virtual ~UMeshComponent()
	{

	}
	virtual void Render() const = 0;
protected:
	std::string m_mesh;
	float m_position[3];
};

class UStaticMeshComponent : public UMeshComponent
{
public:
	UStaticMeshComponent()
	{

	}
	~UStaticMeshComponent()
	{

	}
	void Render() const override
	{
		std::cout << "Wyswietlam  UStaticMeshComponen" << std::endl;
	}
};

class USkinnedMeshComponent : public UMeshComponent
{
public:
	USkinnedMeshComponent()
	{

	}
	~USkinnedMeshComponent()
	{

	}
	void Render() const override
	{
		std::cout << "Wyswietlam  USkinnedMeshComponent" << std::endl;
	}
protected:
	float m_matrixWorld[16];
};

class USkeletalMeshComponent : public USkinnedMeshComponent
{
public:
	USkeletalMeshComponent()
	{

	}
	~USkeletalMeshComponent()
	{

	}
	void Render() const override
	{
		std::cout << "Wyswietlam  USkeletalMeshComponent" << std::endl;
	}
private:
	std::string m_bones;
};

class UWidgetComponent : public UMeshComponent
{
public:
	UWidgetComponent()
	{

	}
	~UWidgetComponent()
	{

	}
	void Render() const override
	{
		std::cout << "Wyswietlam  UWidgetComponent" << std::endl;
	}
private:
	int* m_GUI;
};

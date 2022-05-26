#include "PiguEntity.h"

PiguEntity::PiguEntity(const std::vector<std::string>& filenames) :
	mImages(filenames.begin(), filenames.end())
{
}

int PiguEntity::GetX() const
{
	return mXPos;
}

int PiguEntity::GetY() const
{
	return mYPos;
}

int PiguEntity::GetZ() const
{
	return mZPos;
}

bool PiguEntity::GetSolid() const
{
	return mSolid;
}

int PiguEntity::GetActiveImage() const
{
	return mActiveImage;
}

int PiguEntity::GetWidth() const
{
	return mImages[mActiveImage].GetWidth();
}

int PiguEntity::GetHeight() const
{
	return mImages[mActiveImage].GetHeight();
}

void PiguEntity::SetX(int newX)
{
	mXPos = newX;
}

void PiguEntity::SetY(int newY)
{
	mYPos = newY;
}

void PiguEntity::SetZ(int newZ)
{
	mZPos = newZ;
}

void PiguEntity::SetSolid(bool newSolid)
{
	mSolid = newSolid;
}

void PiguEntity::SetActiveImage(int newActiveImage)
{
	mActiveImage = newActiveImage;
}

void PiguEntity::Draw()
{
	Pigu::PiguRenderer::Draw(mImages[mActiveImage], mXPos, mYPos, mZPos);
}

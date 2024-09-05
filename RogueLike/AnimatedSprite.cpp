#include "AnimatedSprite.h"
#include "World.h"


AnimatedSprite::AnimatedSprite(std::shared_ptr<olc::Sprite> sprite, EAnimationType animType, const FAnimSequence& animSequence) : Tileset(sprite), AnimationType(animType), AnimSequence(animSequence), ElapsedTime(0.0f)
{
}


void AnimatedSprite::DrawAt(float fElapsedTime, olc::vi2d InScreenPosition)
{
    ElapsedTime += fElapsedTime;

    float frameDuration = AnimSequence.AnimationDuration / static_cast<float>(AnimSequence.NumberOfFrames);
    float timeInLoop = std::fmod(ElapsedTime, AnimSequence.AnimationDuration);

    int currentFrame = 0;

    switch (AnimationType)
    {
    case EAnimationType::STILL:
        currentFrame = 0;
        break;
    case EAnimationType::LOOP_ONCE:
        if (ElapsedTime >= AnimSequence.AnimationDuration)
        {
            currentFrame = AnimSequence.NumberOfFrames - 1;
        }
        else
        {
            currentFrame = static_cast<int>(timeInLoop / frameDuration);
        }
        break;
    case EAnimationType::LOOP_FOREVER:
        currentFrame = static_cast<int>(timeInLoop / frameDuration);
        break;
    }

    olc::vi2d sourcePos = AnimSequence.WhichSprite;
    sourcePos.x += currentFrame * (AnimSequence.SpriteSize.x);

    World* pWorld = World::Instance;
    if (pWorld)
    {
        pWorld->DrawPartialSprite(InScreenPosition, Tileset.get(), sourcePos, AnimSequence.SpriteSize);
    }
}

void AnimatedSprite::SetAnimationType(EAnimationType animType)
{
    AnimationType = animType;
    ElapsedTime = 0.0f; // Reset animation timer
}
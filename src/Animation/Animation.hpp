#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <vector>
#include <string>

using AnimationFrame = int;
using AnimationFrameList = std::vector< AnimationFrame >;

class Animation
{   public:

        static const Animation None;

    public:

        Animation( const std::string& name, const AnimationFrameList& list );
        Animation() {}

        virtual AnimationFrame getCurrentFrame() const;
        virtual AnimationFrame popFrame();

        virtual int reset();
        virtual int loop( bool makeLooping = true);
        virtual bool isFinished() const;

        std::string getName() const;
        int map( const Animation& animation );
        
    protected:

        AnimationFrameList  frameList_;
        unsigned int        iCurrentFrame_;
        
        std::string         name_;
        bool                fLooping_;

    public:

        bool operator ==( const Animation& other ) const;
        bool operator !=( const Animation& other ) const;
};

#endif //ANIMATION_HPP

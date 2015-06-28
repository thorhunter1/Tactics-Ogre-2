
#include "Animation/Animation.hpp"
#include "Utils/Debug/DebugUtils.hpp"

const Animation Animation::None = Animation( "none", AnimationFrameList() );


Animation::Animation( const std::string& name, const AnimationFrameList& list )
    : frameList_( list ), iCurrentFrame_( 0 ), name_( name ),
      fLooping_( false )
{
}

AnimationFrame Animation::getCurrentFrame() const
{
    return frameList_[iCurrentFrame_];
}

AnimationFrame Animation::popFrame()
{
    AnimationFrame tmp_frame = frameList_[iCurrentFrame_];

    if( iCurrentFrame_ != frameList_.size() ) ++iCurrentFrame_;
    if( ( iCurrentFrame_ == frameList_.size() ) && fLooping_ ) 
    {
        iCurrentFrame_ = 0;
    }

    return tmp_frame;
}

int Animation::reset()
{
    iCurrentFrame_ = 0;

    return 0;
}

bool Animation::isFinished() const
{
    return ( iCurrentFrame_ == frameList_.size() );
}

int Animation::loop( bool makeLooping )
{
    fLooping_ = makeLooping;

    return 0;
}

std::string Animation::getName() const
{
    return name_;
}

int Animation::map( const Animation& animation )
{
    int ret = 0;

    if( animation.frameList_.size() == frameList_.size() )
    {
        fLooping_ = animation.fLooping_;
        iCurrentFrame_ = animation.iCurrentFrame_;
    }
    else ret = -1;

    TraceReturn( ret, "Can't map animation" );
}

bool Animation::operator ==( const Animation& other ) const
{
    return frameList_ == other.frameList_;
}

bool Animation::operator !=( const Animation& other ) const
{
    return frameList_ != other.frameList_;
}


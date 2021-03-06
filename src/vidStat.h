#include <iostream>
#include <sstream>
#include <string>

struct VidStat {
   bool closed = true;
   bool stopped = true;
   int width = -1;
   int height = -1;
   int frames = -1;
   float duration = -1.0;
   int currentFrame = -1;
   float currentTime = -1;
   float position = -1.0;
   float fps = -1.0;
   float ratio = -1.0;
   int keyframeIndex = -1.0;

   std::string toString() {
      std::ostringstream stream_out;
      stream_out << "Closed: " << closed << "\nStopped: " << stopped
                 << "\nWidth: " << width << "\nHeight: " << height
                 << "\nFrames: " << frames << "\nDuration: " << duration
                 << "\nCurrent Frame: " << currentFrame
                 << "\nCurrent Time: " << currentTime
                 << "\nPosition: " << position << "\nFPS: " << fps
                 << "\nKeyframe Index: " << keyframeIndex << std::endl;
      return stream_out.str();
   };

   void resetCurrentTime() {
      position = -1.0;
      currentTime = -1.0;
      currentFrame = -1.0;
   };

   void updateDimension(float w, float h) {
      width = (w > 0) ? w : width;
      height = (h > 0) ? h : height;
   };

   void updateTotalFrames(float f) { frames = (f > 0) ? f : frames; };

   void updateDuration(float d) {
      duration = (d > 0) ? d : duration;
      fps = ((frames / d) > 0) ? (frames / d) : fps;
   };

   void updateCurrentTimeInfo(float p) {
      position = p;
      currentTime = position * duration;
      currentFrame = currentTime * fps;
   }
};
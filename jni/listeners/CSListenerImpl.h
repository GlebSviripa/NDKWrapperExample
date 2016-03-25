/*
 * CSListenerImpl.h
 *
 *  Created on: 18 мая 2015
 *      Author: gleb
 */

#include <android/log.h>
#include <jni.h>
#include "JavaCache.h"
#include <CoreSignKernel.hpp>
#include <Listener.hpp>



class CSListenerImpl:public CS::Listener
{

private:
    jobject jCSListener;

public:

    EventTypes getEventTypes() const noexcept override;

    void handleEvent(const CS::Event& inEvent) noexcept override;

    CSListenerImpl(jobject _jCSListener)
    {
    	jCSListener = _jCSListener;
    }

    ~CSListenerImpl() {}

};

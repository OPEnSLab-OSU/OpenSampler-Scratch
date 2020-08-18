#pragma once

#include <Components/StateMachine.hpp>
#include <Procedures/SampleStates.hpp>

class SampleStateMachine : public StateMachine {
public:
	SampleStateMachine()
		: StateMachine("sample-state-machine", SampleStateNames::SETUP, SampleStateNames::STOP,
			SampleStateNames::IDLE, SampleStateNames::FINISHED) {}

	void setup() override {
		registerState(SampleStateIdle(), SampleStateNames::IDLE);
		registerState(SampleStateStop(), SampleStateNames::STOP, SampleStateNames::IDLE);
		registerState(SampleStateFinished(), SampleStateNames::FINISHED);

		registerState(SampleStateSetup(), SampleStateNames::SETUP, SampleStateNames::FLUSH);
		registerState(SampleStatePurge(), SampleStateNames::PURGE, SampleStateNames::FLUSH);
		registerState(SampleStateFlush(), SampleStateNames::FLUSH, SampleStateNames::SAMPLE);
		registerState(SampleStateSample(), SampleStateNames::SAMPLE, SampleStateNames::STOP);
	}
};
#pragma once

//#include <KPFoundation.hpp>
#include <Components/StateMachine.hpp>
#include <Application/Application.hpp>
class Button {
public:
	const unsigned short pin;
	int buttonState;
	int lastButtonState;
	unsigned long lastDebounceTime;
	unsigned long debounceDelay;

	Button(const unsigned short n_pin, unsigned long n_delay = DefaultTimesButton::DEBOUNCE_TIME)
		: pin(n_pin), debounceDelay(n_delay) {
		pinMode(pin, INPUT);
	}

	void listen(StateMachine & sm, bool isbusy) {
		if (!isbusy || sm.isBusy()) {
			int reading = digitalRead(pin);

			if (reading != lastButtonState) {
				lastDebounceTime = millis();
			}
			if ((millis() - lastDebounceTime) > debounceDelay) {
				if (reading != buttonState) {
					buttonState = reading;
					if (buttonState == LOW) {
						act(sm);
					}
				}
			}
			lastButtonState = reading;
		}
	}
	void act(StateMachine & sm) {
		if (!sm.isBusy()) {
			sm.begin();
		} else {
			// Application & app = *static_cast<Application *>(sm.controller);
			// sm.stop();
		}
	};
};
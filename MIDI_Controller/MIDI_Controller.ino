/*
 */

#include <SoftwareSerial.h>
#include <midi_Settings.h>
#include <midi_Namespace.h>
#include <midi_Message.h>
#include <midi_Defs.h>
#include <MIDI.h>

const int ledPIN = LED_BUILTIN;

SoftwareSerial softSerial(2, 3);
MIDI_CREATE_INSTANCE(SoftwareSerial, softSerial, midiSS);

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(ledPIN, OUTPUT);
	midiSS.setHandleNoteOn(handleNoteON);
	midiSS.begin(MIDI_CHANNEL_OMNI);
	Serial.begin(115200);
	Serial.println("Arduino Ready.");



}

// the loop function runs over and over again forever
void loop() {
	if (midiSS.read()){
		digitalWrite(ledPIN, HIGH);
		delay(50);
		digitalWrite(ledPIN, LOW);
		Serial.println("MIDI received");
	}


}


void handleNoteON(byte inChannel, byte inNote, byte inVelocity)
{
	Serial.print("Note ON: ");
	Serial.print(inNote);
	Serial.print("\tVel: ");
	Serial.print(inVelocity);
	Serial.print("\tCH: ");
	Serial.println(inChannel);
}
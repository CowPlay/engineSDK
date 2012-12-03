/*
 * SSoundEffectModulator.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTMODULATOR_H_
#define SSOUNDEFFECTMODULATOR_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{

		//! The modulator multiplies an input signal by a carrier signal in the time domain, resulting in tremolo or
		//! inharmonic effects.
		struct SSoundEffectModulator: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectModulator();

				//! Destructor
				virtual ~SSoundEffectModulator();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:

				/* This is the frequency of the carrier signal. If the carrier signal is slowly varying (less than 20 Hz),
				 * the result is a tremolo (slow amplitude variation) effect. If the carrier signal is in the audio range,
				 * audible upper and lower sidebands begin to appear, causing an inharmonic effect. The carrier
				 * signal itself is not heard in the output.
				 * Range: 0.0 to 8000.0
				 * Default 440.0
				 */
				f32 Frequency;

				/* This controls the cutoff frequency at which the input signal is high-pass filtered before being ring
				 * modulated. If the cutoff frequency is 0, the entire signal will be ring modulated. If the cutoff
				 * frequency is high, very little of the signal (only those parts above the cutoff) will be ring
				 * modulated.
				 * Range: 0.0 to 24000.0
				 * Default 800.0
				 */
				f32 HighPassCutoff;

				/* This controls which waveform is used as the carrier signal. Traditional ring modulator and
				 * tremolo effects generally use a sinusoidal carrier. Sawtooth and square waveforms are may
				 * cause unpleasant aliasing.
				 * Range: 0 to 2
				 * Default 2
				 * */
				s32 Waveform;
		};

		//! Default constructor
		SSoundEffectModulator::SSoundEffectModulator() :
				SSoundEffect(), Frequency(440.0), HighPassCutoff(800.0), Waveform(2)
		{
		}

		//! Destructor
		SSoundEffectModulator::~SSoundEffectModulator()
		{

		}

		//! Return effect type
		ESoundEffectType SSoundEffectModulator::getType()
		{
			return ESET_MODULATOR;
		}

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTMODULATOR_H_ */

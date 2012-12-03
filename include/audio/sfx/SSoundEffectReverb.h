/*
 * SSoundEffectReverb.h
 *
 *  Created on: Nov 26, 2012
 *      Author: developer08
 */

#ifndef SSOUNDEFFECTREVERB_H_
#define SSOUNDEFFECTREVERB_H_

#include "SSoundEffect.h"

namespace irrgame
{
	namespace audio
	{

		//! Contains parameters for the EAX Reverb Effect. This effect tries to simulate
		//! how sound behaves in different environments.
		struct SSoundEffectReverb: public SSoundEffect
		{
			public:

				//! Default constructor
				SSoundEffectReverb();

				//! Destructor
				virtual ~SSoundEffectReverb();

				//! Return effect type
				virtual ESoundEffectType getType();

			public:

				// Shared Reverb Properties

				/* The Modal Density controls the coloration of the
				 * late reverb. Lowering the value adds more coloration.
				 * Range: 0.0..1.0
				 * Default: 1.0
				 */
				f32 Density;

				/* The Reverb Diffusion controls the echo density in the reverb decay.
				 * It’s set by default to 1.0, which provides the highest density.
				 * Reducing diffusion gives the reverb a more “grainy” character that
				 * is especially noticeable with percussive sound sources. If you set
				 * a diffusion value of 0.0, the late reverb sounds like a succession
				 * of distinct echoes.
				 * Range: 0.0..1.0
				 * Default: 1.0
				 */
				f32 Diffusion;

				/* The Reverb Gain controls the volume for the reflected sound (both
				 * early reflections and reverberation) that the reverb effect adds to
				 * all sound sources. It sets the maximum amount of reflections and
				 * reverberation added to the final sound mix. The value of the Reverb
				 * Gain ranges from 1.0 (0db, maximum amount) to 0.0 (-100db, no
				 * reflected sound at all).
				 * Range: 0.0..1.0
				 * Default: 0.32
				 */
				f32 Gain;

				/* High frequency part of the Reverb Gain; further tweaks reflected
				 * sound by attenuating it at high frequencies. It controls a low-pass
				 * filter that applies globally to the reflected sound of all sound
				 * sources feeding the particular instance of the reverb effect. The
				 * value of the Reverb Gain HF ranges from 1.0 (0db, no HF filter)
				 * to 0.0 (-100db, virtually no reflected sound).
				 * Range: 0.0..1.0 Default: 0.89*/
				f32 GainHF;

				/* The Decay Time sets the reverberation decay time. It ranges from
				 * 0.1 (typically a small room with very dead surfaces) to 20.0
				 * (typically a large room with very live surfaces).
				 * Range: 0.0..20.0
				 * Default: 1.49
				 */
				f32 DecayTime;

				/* The Decay HF Ratio sets the spectral quality of the Decay Time.
				 * It is the ratio of high-frequency decay time relative to the time
				 * set by Decay Time. The Decay HF Ratio value 1.0 is neutral: the
				 * decay time is equal for all frequencies. As Decay HF Ratio increases
				 * above 1.0, the high-frequency decay time increases so it’s longer
				 * than the decay time at low frequencies. You hear a more brilliant
				 * reverberation with a longer decay at high frequencies. As the
				 * Decay HF Ratio value decreases below 1.0, the high-frequency decay
				 * time decreases so it’s shorter than the decay time of the low
				 * frequencies. You hear a more natural reverberation.
				 * Range: 0.0..2.0
				 * Default: 0.83
				 */
				f32 DecayHFRatio;

				/* The Reflections Gain controls the overall amount of initial
				 * reflections relative to the Gain. The value of Reflections Gain
				 * ranges from a maximum of 3.16 (+10 dB) to a minimum of 0.0 (-100 dB,
				 * no initial reflections at all), and is corrected by the value of
				 * the Gain. The Reflections Gain does not affect the subsequent
				 * reverberation decay. You can increase the amount of initial
				 * reflections to simulate a more narrow space or closer walls,
				 * especially effective if you associate the initial reflections
				 * increase with a reduction in reflections delays by lowering the
				 * value of the Reflection Delay. To simulate open or semi-open
				 * environments, you can maintain the amount of early reflections while
				 * reducing the value of the Late Reverb Gain, which controls later
				 * reflections.
				 * Range: 0.0..3.16
				 * Default: 0.05
				 */
				f32 ReflectionsGain;

				/* The Reflections Delay property is the amount of delay between the arrival time of the direct path
				 * from the source to the first reflection from the source. It ranges from 0 to 300 milliseconds. You
				 * can reduce or increase Reflections Delay to simulate closer or more distant reflective surfaces
				 * and therefore control the perceived size of the room.
				 * Range: 0.0 to 0.3
				 * Default: 0.007
				 */
				f32 ReflectionsDelay;

				/* The Late Reverb Gain controls the overall amount of later reverberation
				 * relative to the Gain. The value of Late Reverb Gain ranges from a
				 * maximum of 10.0 (+20 dB) to a minimum of 0.0 (-100 dB, no late
				 * reverberation at all). Note that Late Reverb Gain and Decay Time are
				 * independent properties: If you adjust the Decay Time without changing the
				 * Late Reverb Gain, the total intensity (the averaged square of the amplitude)
				 * of the late reverberation remains constant.
				 * Range: 0.0..10.0
				 * Default: 1.26
				 */
				f32 LateReverbGain;

				/* The Late Reverb Delay defines the begin time of the late reverberation
				 * relative to the time of the initial reflection (the first of the early
				 * reflections). It ranges from 0 to 100 milliseconds. Reducing or increasing
				 * Late Reverb Delay is useful for simulating a smaller or larger room.
				 * Range: 0.0..0.1
				 * Default: 0.011
				 */
				f32 LateReverbDelay;

				/* The Air Absorption Gain HF controls the distance-dependent attenuation at
				 * high frequencies caused by the propagation medium. It applies to reflected
				 * sound only. You can use Air Absorption Gain HF to simulate sound transmission
				 * through foggy air, dry air, smoky atmosphere, and so on. The default value
				 * is 0.994 (-0.05 dB) per meter, which roughly corresponds to typical condition
				 * of atmospheric humidity, temperature, and so on. Lowering the value simulates
				 * a more absorbent medium (more humidity in the air, for example); raising the
				 * value simulates a less absorbent medium (dry desert air, for example).
				 * Range: 0.892..1.0
				 * Default: 0.994
				 */
				f32 AirAbsorptionGainHF;

				/* The Room Rolloff Factor is one of two methods available to attenuate the
				 * reflected sound (containing both reflections and reverberation) according
				 * to source-listener distance. Setting the Room Rolloff Factor value to 1.0
				 * specifies that the reflected sound will decay by 6 dB every time the distance
				 * doubles. Any value other than 1.0 is equivalent to a scaling factor applied to
				 * the quantity specified by the listener distance. The default value of Room
				 * Rolloff Factor is 0.0 because the default reverb effect naturally manages the
				 * reflected sound level automatically for each sound source to simulate the natural
				 * rolloff of reflected sound vs. distance in typical rooms. You can use the Room
				 * Rolloff Factor as an option to automatic control so you can exaggerate or replace
				 * the default automatically-controlled rolloff.
				 * Range: 0.0..10.0
				 * Default: 0.0
				 */
				f32 RoomRolloffFactor;

				/* When at true, the high-frequency decay time automatically stays below a limit
				 * value that’s derived from the setting of the property Air Absorption HF. This
				 * limit applies regardless of the setting of the Decay HF Ratio, and the limit
				 * doesn’t affect the value of Decay HF Ratio. This limit, when on, maintains a natural
				 * sounding reverberation decay by allowing you to increase the value of Decay Time
				 * without the risk of getting an unnaturally long decay time at high frequencies.
				 * If parameter is false, high-frequency decay time isn’t automatically limited.
				 * Default: true
				 */
				bool DecayHFLimit;

				// Additional EAX Reverb Properties

				/* The Reverb Gain LF property further tweaks reflected sound by attenuating it at low frequencies.
				 * It controls a high-pass filter that applies globally to the reflected sound of all sound sources
				 * feeding the particular instance of the reverb effect. The value of the Reverb Gain LF property
				 * ranges from 1.0 (0db) (no filter) to 0.0 (-100db) (virtually no reflected sound). LF Reference sets
				 * the frequency at which the value of this property is measured.
				 * Range: 0.0 to 1.0
				 * Default: 0.0
				 */
				f32 GainLF;

				/* The Decay LF Ratio property adjusts the spectral quality of the Decay Time parameter. It is the
				 * ratio of low-frequency decay time relative to the time set by Decay Time. The Decay LF Ratio
				 * value 1.0 is neutral: the decay time is equal for all frequencies. As Decay LF Ratio increases
				 * above 1.0, the low-frequency decay time increases so it's longer than the decay time at mid
				 * frequencies. You hear a more booming reverberation with a longer decay at low frequencies. As
				 * the Decay LF Ratio value decreases below 1.0, the low-frequency decay time decreases so it's
				 * shorter than the decay time of the mid frequencies. You hear a more tinny reverberation.
				 * Range: 0.1 to 20.0
				 * Default: 1.0
				 */
				f32 DecayLFRatio;

				/* The Reflections Pan property is a 3D vector that controls the spatial distribution of the cluster of
				 * early reflections. The direction of this vector controls the global direction of the reflections, while
				 * its magnitude controls how focused the reflections are towards this direction.
				 * It is important to note that the direction of the vector is interpreted in the coordinate system of the
				 * user, without taking into account the orientation of the virtual listener. For instance, assuming a
				 * four-point loudspeaker playback system, setting Reflections Pan to (0, 0, 0.7) means that the
				 * reflections are panned to the front speaker pair, whereas as setting of (0, 0, -0.7) pans the
				 * reflections towards the rear speakers. These vectors follow the a left-handed co-ordinate system.
				 * If the magnitude of Reflections Pan is zero (the default setting), the early reflections come evenly
				 * from all directions. As the magnitude increases, the reflections become more focused in the
				 * direction pointed to by the vector. A magnitude of 1.0 would represent the extreme case, where
				 * all reflections come from a single direction.
				 * Default: vector3df(0.0f, 0.0f, 0.0f)
				 */
				vector3df ReflectionsPan;

				/* The Late Reverb Pan property is a 3D vector that controls the spatial distribution of the late
				 * reverb. The direction of this vector controls the global direction of the reverb, while its magnitude
				 * controls how focused the reverb are towards this direction. The details under Reflections Pan,
				 * above, also apply to Late Reverb Pan.
				 * Default: vector3df(0.0f, 0.0f, 0.0f)
				 */
				vector3df LateReverbPan;

				/* Echo Time controls the rate at which the cyclic echo repeats itself along the
				 * reverberation decay. For example, the default setting for Echo Time is 250 ms. causing the echo
				 * to occur 4 times per second. Therefore, if you were to clap your hands in this type of
				 * environment, you will hear four repetitions of clap per second.
				 * Range: 0.075 to 0.25
				 * Default: 0.25
				 */
				f32 EchoTime;

				/* Echo Depth introduces a cyclic echo in the reverberation decay, which will be noticeable with
				 * transient or percussive sounds. A larger value of Echo Depth will make this effect more
				 * prominent.
				 * Together with Reverb Diffusion, Echo Depth will control how long the echo effect will persist along
				 * the reverberation dechear a larger number
				 * of repetitions of the echo, which will wash out later in the reverberation decay. If Diffusion is set
				 * to 0.0 and Echo Depth is set to 1.0, the echo will persist distinctly until the end of the
				 * reverberation decay.
				 * Range: 0.0 to 1.0
				 * Default: 0.0
				 */
				f32 EchoDepth;

				/* Using these two properties below, you can create a pitch modulation in the reverberant sound. This will
				 * be most noticeable applied to sources that have tonal color or pitch. You can use this to make
				 * some trippy effects! Modulation Time controls the speed of the vibrato (rate of periodic changes in pitch).
				 * Range: 0.004 to 4.0
				 * Default: 0.25
				 */
				f32 ModulationTime;

				/* Modulation Depth controls the amount of pitch change. Low values of Diffusion will contribute to
				 * reinforcing the perceived effect by reducing the mixing of overlapping reflections in the
				 * reverberation decay.
				 * Range: 0.0 to 1.0
				 * Default: 0.0
				 */
				f32 ModulationDepth;

				/* The properties HF Reference and LF Reference determine respectively the frequencies at which
				 * the high-frequency effects and the low-frequency effects created by EAX Reverb properties are
				 * measured, for example Decay HF Ratio and Decay LF Ratio.
				 * Note that it is necessary to maintain a factor of at least 10 between these two reference
				 * frequencies so that low frequency and high frequency properties can be accurately controlled and
				 * will produce independent effects. In other words, the LF Reference value should be less than
				 * 1/10 of the HF Reference value.
				 * Range: 1000.0 to 20000.0
				 * Default: 5000.0
				 */
				f32 HFReference;

				/* See HFReference.
				 * Range: 20.0 to 1000.0
				 * Default: 250.0
				 */
				f32 LFReference;

		};

		//! Default constructor
		SSoundEffectReverb::SSoundEffectReverb() :
				SSoundEffect(), Density(1.0), Diffusion(1.0), Gain(0.32), GainHF(
						0.89), DecayTime(1.49), DecayHFRatio(0.83), ReflectionsGain(
						0.05), ReflectionsDelay(0.007), LateReverbGain(1.26), LateReverbDelay(
						0.011), AirAbsorptionGainHF(0.994), RoomRolloffFactor(
						0.0), DecayHFLimit(true), GainLF(1.0), DecayLFRatio(
						1.0), ReflectionsPan(vector3df(0.0, 0.0, 0.0)), LateReverbPan(
						vector3df(0.0, 0.0, 0.0)), EchoTime(0.25), EchoDepth(
						0.0), ModulationTime(0.25), ModulationDepth(0.0), HFReference(
						5000.0), LFReference(250.0)

		{
		}

		//! Destructor
		SSoundEffectReverb::~SSoundEffectReverb()
		{

		}

		//! Return effect type
		ESoundEffectType SSoundEffectReverb::getType()
		{
			return ESET_REVERB;
		}

	}  // namespace audio
}  // namespace irrgame

#endif /* SSOUNDEFFECTREVERB_H_ */

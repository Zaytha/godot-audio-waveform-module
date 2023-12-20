#ifndef AUDIO_STREAM_PREVIEW_H
#define AUDIO_STREAM_PREVIEW_H

#include "core/object/ref_counted.h"

class AudioStreamPreview : public RefCounted {
	GDCLASS(AudioStreamPreview, RefCounted);
	friend class AudioStream;
	Vector<uint8_t> preview;
	float length;

	friend class AudioStreamPreviewGenerator;
	uint64_t version = 1;

protected:
	static void _bind_methods();

public:
	uint64_t get_version() const { return version; }
	float get_length() const;
	float get_max(float p_time, float p_time_next) const;
	float get_min(float p_time, float p_time_next) const;

	AudioStreamPreview();
};


#endif // AUDIO_STREAM_PREVIEW_H

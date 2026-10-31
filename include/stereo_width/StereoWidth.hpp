#pragma once

#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstddef>

namespace stereo_width{

class StereoWidth final{
public:
	void setWidth(float width) noexcept{
		if (std::isfinite(width)){
			width_.store(std::clamp(width, 0.0f, 2.0f), std::memory_order_relaxed);
		}
	}

	void process(float* left, float* right, std::size_t frameCount) const noexcept{
		if (left == nullptr || right == nullptr || frameCount == 0){
			return;
		}

		const float width = width_.load(std::memory_order_relaxed);
		if (width == 1.0f){
			return;
		}

		for (std::size_t frame = 0; frame < frameCount; ++frame){
			const float l = left[frame];
			const float r = right[frame];
			const float mid = (l + r) * 0.5f;
			const float side = (l - r) * 0.5f * width;

			left[frame] = mid + side;
			right[frame] = mid - side;
		}
	}

private:
	static_assert(std::atomic<float>::is_always_lock_free);
	std::atomic<float> width_{1.0f};
};

}

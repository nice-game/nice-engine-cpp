#include <vector>

template <typename T>
class Vec {
public:
	using size_type = size_t;

	std::vector<T> inner;

	Vec() {}
	Vec(size_type count, const T& value) : inner(count, value) {}
	explicit Vec(size_type count) : inner(count) {}
	template<class InputIt>
	Vec(InputIt first, InputIt last) : inner(first, last) {}
	Vec(const Vec& other) = delete;
	Vec(Vec&& other) noexcept : inner(other.inner) {}
	Vec(std::initializer_list<T> init) : inner(init) {}

	/* Element access */

	T* data() noexcept { return inner.data(); }
	const T* data() const noexcept { return inner.data(); }

	/* Capacity */

	size_type size() const noexcept { return inner.size(); }

	/* Modifiers */

	void push(const T& value) { inner.push_back(value); }
	void push(T&& value) { inner.push_back(value); }
};
#ifndef HOLY_TRINITY_HPP
#define HOLY_TRINITY_HPP

#define HOLY_TRINITY_FULL(NAME)                       \
    NAME() noexcept                        = default; \
    ~NAME()                                = default; \
    NAME(const NAME&) noexcept             = default; \
    NAME& operator=(const NAME&) noexcept  = default; \
    NAME(NAME&& other) noexcept            = default; \
    NAME& operator=(NAME&& other) noexcept = default;

#define HOLY_TRINITY_MOST(NAME)                       \
    ~NAME()                                = default; \
    NAME(const NAME&) noexcept             = default; \
    NAME& operator=(const NAME&) noexcept  = default; \
    NAME(NAME&& other) noexcept            = default; \
    NAME& operator=(NAME&& other) noexcept = default;

#endif // !HOLY_TRINITY_HPP

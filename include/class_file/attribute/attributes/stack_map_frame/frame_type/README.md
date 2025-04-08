One thing to note about these frame types is that the `frame_type` attribute
holds a `uint8_t` value which can be paired with `frame_type_get(value)` to
retrieve the actual tag if needed (the tags are defined for certain ranges of
values.)

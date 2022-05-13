# utf-benchmark

## Credits

This benchmark uses code from https://github.com/simdutf/simdutf
You could find it in src/simd/ directory


## running
```bash
npm ci
npm run build
```

`ascii` example is not giving much, because non-ascii symbols are encoded like that `\u201d`

All examples run with nodejs v18.1.0 on Linux

Size: 456kb
```
$ npm run utf
> utf-benchmark@1.0.0 utf
> node index.js twitter

JSON.parse(data) x 675 ops/sec ±0.52% (94 runs sampled)
JSON.parse(buffer.toString('utf8')) x 356 ops/sec ±0.51% (90 runs sampled)
JSON.parse(native.decode(buffer)) x 362 ops/sec ±0.36% (90 runs sampled)
JSON.parse(native.decodeSimd(buffer)) x 521 ops/sec ±0.74% (88 runs sampled)
JSON.parse(textDecoder.decode(buffer)) x 426 ops/sec ±1.76% (89 runs sampled)
Fastest is JSON.parse(data)
buffer.toString('utf8') x 740 ops/sec ±1.65% (85 runs sampled)
native.decode(buffer) x 747 ops/sec ±1.62% (87 runs sampled)
native.decodeSimd(buffer) x 2,432 ops/sec ±1.79% (83 runs sampled)
textDecoder.decode(buffer) x 1,164 ops/sec ±1.59% (83 runs sampled)
Fastest is native.decodeSimd(buffer)
```

Size: 3.2mb
```
$ npm run ascii
> utf-benchmark@1.0.0 ascii
> node index.js gsoc-2018

JSON.parse(data) x 244 ops/sec ±1.22% (85 runs sampled)
JSON.parse(buffer.toString('utf8')) x 187 ops/sec ±1.15% (76 runs sampled)
JSON.parse(native.decode(buffer)) x 190 ops/sec ±0.76% (86 runs sampled)
JSON.parse(native.decodeSimd(buffer)) x 189 ops/sec ±0.84% (85 runs sampled)
JSON.parse(textDecoder.decode(buffer)) x 93.55 ops/sec ±1.44% (67 runs sampled)
Fastest is JSON.parse(data)
buffer.toString('utf8') x 961 ops/sec ±1.45% (90 runs sampled)
native.decode(buffer) x 975 ops/sec ±0.82% (93 runs sampled)
native.decodeSimd(buffer) x 914 ops/sec ±0.75% (95 runs sampled)
textDecoder.decode(buffer) x 337 ops/sec ±1.85% (90 runs sampled)
Fastest is native.decode(buffer)

```

Size: 3mb
```
$ npm run ascii-decoded
> utf-benchmark@1.0.0 ascii-decoded
> node index.js gsoc-2018-decoded

JSON.parse(data) x 148 ops/sec ±0.78% (79 runs sampled)
JSON.parse(buffer.toString('utf8')) x 79.27 ops/sec ±0.49% (69 runs sampled)
JSON.parse(native.decode(buffer)) x 79.32 ops/sec ±0.60% (69 runs sampled)
JSON.parse(native.decodeSimd(buffer)) x 110 ops/sec ±0.42% (80 runs sampled)
JSON.parse(textDecoder.decode(buffer)) x 100.00 ops/sec ±1.13% (72 runs sampled)
Fastest is JSON.parse(data)
buffer.toString('utf8') x 167 ops/sec ±0.55% (84 runs sampled)
native.decode(buffer) x 169 ops/sec ±0.46% (85 runs sampled)
native.decodeSimd(buffer) x 403 ops/sec ±0.70% (92 runs sampled)
textDecoder.decode(buffer) x 339 ops/sec ±1.91% (81 runs sampled)
Fastest is native.decodeSimd(buffer)
```

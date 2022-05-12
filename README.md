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

All examples run with nodejs v18.0.0 on Linux
```
$ npm run utf
> utf-benchmark@1.0.0 utf
> node index.js twitter

JSON.parse(data) x 715 ops/sec ±0.77% (92 runs sampled)
JSON.parse(buffer.toString('utf8')) x 365 ops/sec ±1.16% (86 runs sampled)
JSON.parse(native.decode(buffer)) x 360 ops/sec ±1.31% (84 runs sampled)
JSON.parse(native.decodeSimd(buffer)) x 533 ops/sec ±1.37% (88 runs sampled)
Fastest is JSON.parse(data)
buffer.toString('utf8') x 757 ops/sec ±1.50% (83 runs sampled)
native.decode(buffer) x 734 ops/sec ±1.62% (85 runs sampled)
native.decodeSimd(buffer) x 2,611 ops/sec ±1.55% (80 runs sampled)
Fastest is native.decodeSimd(buffer)
```

```
$ npm run ascii
> utf-benchmark@1.0.0 ascii
> node index.js gsoc-2018

JSON.parse(data) x 250 ops/sec ±0.71% (90 runs sampled)
JSON.parse(buffer.toString('utf8')) x 193 ops/sec ±0.74% (80 runs sampled)
JSON.parse(native.decode(buffer)) x 192 ops/sec ±0.68% (80 runs sampled)
JSON.parse(native.decodeSimd(buffer)) x 192 ops/sec ±0.61% (81 runs sampled)
Fastest is JSON.parse(data)
buffer.toString('utf8') x 974 ops/sec ±0.83% (94 runs sampled)
native.decode(buffer) x 1,000 ops/sec ±0.67% (95 runs sampled)
native.decodeSimd(buffer) x 998 ops/sec ±0.22% (96 runs sampled)
Fastest is native.decodeSimd(buffer)

```

```
$ npm run ascii-decoded
> utf-benchmark@1.0.0 ascii-decoded
> node index.js gsoc-2018-decoded

JSON.parse(data) x 146 ops/sec ±0.78% (78 runs sampled)
JSON.parse(buffer.toString('utf8')) x 79.61 ops/sec ±0.34% (68 runs sampled)
JSON.parse(native.decode(buffer)) x 78.77 ops/sec ±0.69% (68 runs sampled)
JSON.parse(native.decodeSimd(buffer)) x 109 ops/sec ±0.77% (80 runs sampled)
Fastest is JSON.parse(data)
buffer.toString('utf8') x 161 ops/sec ±0.68% (81 runs sampled)
native.decode(buffer) x 161 ops/sec ±0.32% (82 runs sampled)
native.decodeSimd(buffer) x 397 ops/sec ±0.54% (87 runs sampled)
Fastest is native.decodeSimd(buffer)
```

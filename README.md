# utf-benchmark

## Credits

This benchmark uses code from https://github.com/simdutf/simdutf
You could find it in src/external/ directory


## running
```bash
npm ci
npm run build
```

`ascii` example is not giving much, because non-ascii symbols are encoded like that `\u201d`

All examples run with nodejs v18.0.0
```
$ npm run utf
> utf-benchmark@1.0.0 utf
> node index.js twitter

JSON.parse(data) x 638 ops/sec ±0.39% (91 runs sampled)
JSON.parse(data.toString('utf8')) x 332 ops/sec ±0.87% (86 runs sampled)
JSON.parse(native.decode(buffer)) x 348 ops/sec ±0.33% (88 runs sampled)
JSON.parse(native.decodeSimd(buffer)) x 522 ops/sec ±0.84% (89 runs sampled)
Fastest is JSON.parse(data)
data.toString('utf8') x 698 ops/sec ±0.45% (93 runs sampled)
native.decode(buffer) x 668 ops/sec ±0.70% (90 runs sampled)
native.decodeSimd(buffer) x 2,413 ops/sec ±0.77% (92 runs sampled)
Fastest is native.decodeSimd(buffer)
```

```
$ npm run ascii
> utf-benchmark@1.0.0 ascii
> node index.js gsoc-2018

JSON.parse(data) x 215 ops/sec ±0.94% (84 runs sampled)
JSON.parse(data.toString('utf8')) x 162 ops/sec ±0.75% (83 runs sampled)
JSON.parse(native.decode(buffer)) x 174 ops/sec ±0.49% (88 runs sampled)
JSON.parse(native.decodeSimd(buffer)) x 171 ops/sec ±0.45% (84 runs sampled)
Fastest is JSON.parse(data)
data.toString('utf8') x 801 ops/sec ±0.57% (93 runs sampled)
native.decode(buffer) x 804 ops/sec ±0.53% (93 runs sampled)
native.decodeSimd(buffer) x 795 ops/sec ±0.36% (95 runs sampled)
Fastest is native.decode(buffer),data.toString('utf8')

```

```
$ npm run ascii-decoded
> utf-benchmark@1.0.0 ascii-decoded
> node index.js gsoc-2018-decoded

JSON.parse(data) x 160 ops/sec ±1.39% (81 runs sampled)
JSON.parse(data.toString('utf8')) x 71.81 ops/sec ±1.05% (74 runs sampled)
JSON.parse(native.decode(buffer)) x 76.08 ops/sec ±0.49% (78 runs sampled)
JSON.parse(native.decodeSimd(buffer)) x 117 ops/sec ±0.23% (74 runs sampled)
Fastest is JSON.parse(data)
data.toString('utf8') x 141 ops/sec ±0.26% (80 runs sampled)
native.decode(buffer) x 141 ops/sec ±0.44% (80 runs sampled)
native.decodeSimd(buffer) x 347 ops/sec ±0.62% (87 runs sampled)
Fastest is native.decodeSimd(buffer)
```

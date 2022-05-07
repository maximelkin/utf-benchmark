const Benchmark = require('benchmark');
const fs = require('fs');
const assert = require('assert').strict;

const native = require('./build/Release/benchmark.node');


const buffer = fs.readFileSync(`./data/${process.argv[2] || 'gsoc-2018'}.json`);

const strData = buffer.toString('utf8');


assert.deepEqual(native.decode(buffer), strData);
assert.deepEqual(JSON.parse(native.decode(buffer)), JSON.parse(strData));
assert.deepEqual(native.decodeSimd(buffer), strData);
assert.deepEqual(JSON.parse(native.decodeSimd(buffer)), JSON.parse(strData));

function runJSON(cb) {
    const suite = new Benchmark.Suite;
    suite
        .add('JSON.parse(data)', function () {
            JSON.parse(strData);
        })
        .add('JSON.parse(buffer.toString(\'utf8\'))', function () {
            JSON.parse(buffer.toString('utf8'));
        })
        .add('JSON.parse(native.decode(buffer))', function () {
            JSON.parse(native.decode(buffer));
        })
        .add('JSON.parse(native.decodeSimd(buffer))', function () {
            JSON.parse(native.decodeSimd(buffer));
        })
        .on('cycle', function (event) {
            console.log(String(event.target));
        })
        .on('complete', function () {
            console.log('Fastest is ' + this.filter('fastest').map('name'));
            if (cb) cb();
        })
        // run async
        .run({'async': true});
}


function runDecode(cb) {
    const suite = new Benchmark.Suite;
    suite
        .add('buffer.toString(\'utf8\')', function () {
            buffer.toString('utf8');
        })
        .add('native.decode(buffer)', function () {
            native.decode(buffer);
        })
        .add('native.decodeSimd(buffer)', function () {
            native.decodeSimd(buffer);
        })
        .on('cycle', function (event) {
            console.log(String(event.target));
        })
        .on('complete', function () {
            console.log('Fastest is ' + this.filter('fastest').map('name'));
            if (cb) cb();
        })
        // run async
        .run({'async': true});
}

runJSON(() => {
    setTimeout(runDecode, 1000)
})


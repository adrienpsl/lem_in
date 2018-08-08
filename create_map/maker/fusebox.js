const {FuseBox, WebIndexPlugin} = require("fuse-box");

const fuse = FuseBox.init({
  homeDir : "src/",
  target : "browser@es5",
  output : "dist/$name.js",
  plugins : [
    WebIndexPlugin({template:"./index.html"})
  ]
});
fuse.dev();
fuse.bundle("app").instructions(">index.ts")
fuse.run();
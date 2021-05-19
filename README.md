# env(1) implementation
This is a basic implementation of the env utility. This repo was created as an exercise to familiarize with the C programming language.

## Running
To run first create a build of the app by running the following:
```
make
```
You should now have a file entitled `env_lg` in the root directory. You can now run this by invoking the output file with the following command, which with out any additional arguments will print your current environment.
```
./env_lg
```

You can run the help command to view the usage with:
```
./env_lg -h
```

The usage is as follows:
```
./env_lg [NAME=VALUE...] [COMMAND [ARG...]]
```

## Tests
You can invoke the unit tests with the following:
```
make run_tests
```

## Debugging
You are able to enter debug mode with the following command:
```
make debug
```

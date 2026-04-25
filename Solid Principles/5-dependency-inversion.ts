// Dependency Inversion Principle

// High-level modules should not depend on low-level modules. Both should depend on abstractions. It means
// Don’t depend on concrete classes — depend on interfaces (or abstractions) like RemotePC singleton class will depend
// on a datastore interface but not concrete so we can switch to cli.datastore or electron.datastore.

// How Deepam uses - 
/*
    Say datastore is a member;
    datastore = cli.datastore or
    datastore = electron.datastore

    We are injecting the member type to make it more modular
    Dependency injection is a way to implement Dependency Inversion
*/
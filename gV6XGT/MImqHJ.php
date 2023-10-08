class ARVRBuilder {
    public function __construct($ar_sdk, $vr_sdk) {
        $this->ar_sdk = $ar_sdk;
        $this->vr_sdk = $vr_sdk;
    }

    public function buildARApplication($scene, $models) {
        // Load the scene and models.
        $scene = $this->ar_sdk->loadScene($scene);
        $models = array();
        foreach ($models as $model) {
            $models[] = $this->ar_sdk->loadModel($model);
        }

        // Add the models to the scene.
        foreach ($models as $model) {
            $scene->addModel($model);
        }

        // Return the scene.
        return $scene;
    }

    public function buildVRApplication($scene, $models) {
        // Load the scene and models.
        $scene = $this->vr_sdk->loadScene($scene);
        $models = array();
        foreach ($models as $model) {
            $models[] = $this->vr_sdk->loadModel($model);
        }

        // Add the models to the scene.
        foreach ($models as $model) {
            $scene->addModel($model);
        }

        // Return the scene.
        return $scene;
    }

    public function optimizeARApplication($scene) {
        // TODO: Implement this method to optimize the AR application scene.
    }

    public function optimizeVRApplication($scene) {
        // TODO: Implement this method to optimize the VR application scene.
    }
}

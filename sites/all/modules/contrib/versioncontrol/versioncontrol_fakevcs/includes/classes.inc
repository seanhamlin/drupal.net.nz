<?php
/**
 * @file
 *   An example of the classes a backend would need.
 *   Please notice this is just a subsetimplementation
 */
class VersioncontrolFakeBackend extends VersioncontrolBackend {

  public $classes = array(
    'repo'      => 'VersioncontrolFakeRepository',
    'operation' => 'VersioncontrolFakeOperation',
    'item'      => 'VersioncontrolFakeItem',
  );

  public function __construct() {
    // The user-visible name of the VCS.
    $this->name = 'FakeVCS';
    // A short description of the VCS, if possible not longer than one or
    // two sentences.
    $this->description = t('FakeVCS is a version control system that is specifically capable in doing everything that any other version control system might ever do.');
    // Our example VCS supports all possible capabilities, but they are
    // optional.
    $this->capabilities = array(
        // Able to retrieve a file or its revision number based on a global
        // revision identifier.
        VERSIONCONTROL_CAPABILITY_ATOMIC_COMMITS,

        // The version control system assigns revisions not only to files
        // but also to directories.
        VERSIONCONTROL_CAPABILITY_DIRECTORY_REVISIONS,
    );
  }

  /**
   * Overwrite
   */
  function isUsernameValid(&$username) {
    // Continuing the email-style username example from above.
    return valid_email_address($username);
  }

}

class VersioncontrolFakeRepository extends VersioncontrolRepository {

  public function formatRevisionIdentifier($revision, $format = 'full') {
    switch ($format) {
    case 'full':
    case 'short':
    default:
      // Suppose we're a distributed VCS backend and have an SHA-1 hash:
      // $revision == '30581e4ec3347d1294ec05a91eec1a8588e5993c'
      // Let's return only the first 12 characters of the revision identifier,
      // like Mercurial (including hgweb) does by default.
      return substr($revision, 0, 12);

      // SVN also wants to format revisions in a slightly custom way:
      return 'r'. $revision;
    }
  }

}

class VersioncontrolFakeOperation extends VersioncontrolOperation {

  public $parent_commit = '';

  // Asumming for fakevcs is better retrieving information if we have the
  // parent commit revision, we interact to have CRUD around that in out own
  // table.

  protected function backendInsert($options) {
    db_insert('versioncontrol_fakevcs_operations')
      ->fields(array(
        'vc_op_id' => $this->vc_op_id,
        'parent_commit' => $this->parent_commit,
      ))
      ->execute();
  }

  protected function backendUpdate($options) {
    db_update('versioncontrol_fakevcs_operations')
      ->fields(array(
        'vc_op_id' => $this->vc_op_id,
        'parent_commit' => $this->parent_commit,
      ))
      ->condition('vc_op_id', $this->vc_op_id)
      ->execute();
  }

  protected function backendDelete($options) {
    db_delete('versioncontrol_fakevcs_operations')
      ->condition('vc_op_id', $this->vc_op_id)
      ->execute();
  }
}

class VersioncontrolGitOperationController extends VersioncontrolOperationController {
  /**
   * Extend the base query with the fakevcs backend's additional data in
   * {versioncontrol_fakevcs_operations}.
   *
   * @return SelectQuery
   */
  protected function buildQueryBase($ids, $conditions) {
    $query = parent::buildQueryBase($ids, $conditions);
    $alias = $this->addTable($query, 'versioncontrol_fakevcs_operations', 'vcfo', 'base.vc_op_id = vcfo.vc_op_id');
    $query->fields($alias, drupal_schema_fields_sql('versioncontrol_fakevcs_operations'));
    return $query;
  }
}

class VersioncontrolFakeItem extends VersioncontrolItem {
}
